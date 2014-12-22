/* Exercise 1-22 from K+R
 * Copyright (c) 2014 Răzvan Mocanu
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/*
 * Write a program to "fold" long input lines into two or more shorter
 * lines after the last non-blank character that occurs before the n-th
 * column of input. Make sure your program does something intelligent
 * with very long lines, and if there are no blanks or tabs before the
 * specified column.
 */

#include <stdio.h>

#define N 80	/* Fold column. */
#define TAB 8	/* Size of a tab stop. */

void fold(void);
void print(char c);

char s[N];	/* Temporary store for consecutive non-blanks. */
int z;		/* Length of `s`. */
int n;		/* Column of last character in line. */
int f;		/* Column of last non-blank in line. */
int t;		/* Remaining number of characters until next tab stop. */

int main()
{
	int c;

	n = z = f = 0;
	t = TAB;

	while ((c = getchar()) != EOF) {
		/* Should the line be folded? */
		if (n >= N - 1)
			fold();

		if (c == '\n')
			print(c);
		else if (c == ' ' || c == '\t') {
			if (f == 0)
				/*
				 * Print blanks at beginning of lines.
				 * If a long line is made only of blanks, prefer to fold the
				 * line instead of printing all of them on a new line.
				 */
				putchar(c);
			else {
				/*
				 * Potential blank before the fold column.
				 * Store it in case a fold is required. In this case
				 * the blanks that were at the end of the folded line
				 * must be printed at the beginning of the new line
				 * to maintain the input's integrity.
				 */
				s[z] = c;
				++z;
			}

			if (c == ' ') {
				++n;
				--t;
				if (t == 0)
					t = TAB;
			} else {
				n = n + t;
				t = TAB;
			}
		} else {
			/*
			 * A new non-blank character.
			 * This will be the new fold character of the line.
			 * Print it together with any temporarily stored
			 * non-blanks before it.
			 */
			print(c);

			++n;
			--t;
			if (t == 0)
				t = TAB;

			f = n;
		}
	}

	return 0;
}

/*
 * Folds a line by printing a newline character followed by any
 * stored blanks in `s` that were at the end of the line.
 */
void fold(void)
{
	int i;

	n = f = 0;

	putchar('\n');

	for (i = 0; i < z; ++i) {
		putchar(s[i]);

		if (s[i] == ' ') {
			++n;
			--t;
		} else {
			n = n + t;
			t = TAB;
		}
	}

	z = 0;
}

/*
 * Prints the character c, prefixed by the blanks stored in `s`.
 * This is done when the blanks were not actually at the end of the line,
 * i.e. another non-blank character was encoutered in the line after them,
 * or when a newline character is encountered.
 */
void print(char c)
{
	int i;

	for (i = 0; i < z; ++i)
		putchar(s[i]);

	putchar(c);

	if (c == '\n') {
		n = f = 0;
		t = TAB;
	}

	z = 0;
}