/*
 * Exercise 1-23 from K+R
 * Copyright (c) 2019 Răzvan Mocanu
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
 * Write a program to remove all comments from a C program. Don't forget
 * to handle quoted strings and character constants properly. C comments
 * don't nest.
 */

#include <stdio.h>

int quote(int);
int comment(void);

int main()
{
	int b;	/* Input stream buffer. */
	int c;

	b = 0;
	c = getchar();

	while (c != EOF) {
		/* Is it the beginning of a character or string constant? */
		if (c == '\'' || c == '"')
			c = quote(c);
		/* Is it the beginning of a comment? */
		else if (c == '/') {
			/* Look at the next character to confirm. */
			if ((c = getchar()) != EOF) {
				if (c == '*')
					c = comment();
				else {
					/*
					 * '/' might be followed by another '/'.
					 * Put the character in the input stream buffer so that it
					 * is used as the current character in the next iteration.
					 */
					b = c;
					/* Print the previous character. */
					putchar('/');
				}
			}
		} else
			putchar(c);

		if (b != 0) {
			c = b;
			b = 0;
		} else if (c != EOF)
			c = getchar();
	}

	return 0;
}

/*
 * Parses a character or string constant. Takes into
 * account the existence of escape sequences. Comments
 * cannot be placed inside these constants so everything
 * is output.
 */
int quote(int q)
{
	int c;

	/* Display the beginning quote character. */
	putchar(q);
	c = getchar();

	/* Read until the end of the constant. */
	while (c != EOF && c != q) {
		putchar(c);

		/* Is it the beginning of an escape sequence? */
		if (c == '\\')
			/*
			 * The escape sequence might escape the quote character.
			 * If this would be left unhandled, it would be mistaken
			 * for the end of the constant. Read the next character
			 * and print it to make sure quotes in escape sequences
			 * are correctly skipped.
			 */
			if ((c = getchar()) != EOF)
				putchar(c);

		if (c != EOF)
			c = getchar();
	}

	/* Print the quote at the end of the constant. */
	if (c != EOF)
		putchar(c);

	return c;
}

/*
 * Parses a comment. Comments cannot be nested.
 * Does not output anything inside, effectively
 * removing the comment from the input stream.
 */
int comment(void)
{
	int c;
	int s;	/* Flag to indicate the end of the comment. */

	s = 0;
	c = getchar();

	while (s != 1) {
		/* Read until the beginning of the end of the comment. */
		while (c != EOF && c != '*')
			c = getchar();

		if (c == EOF)
			s = 1;
		else {
			/* Read the next character to confirm the end. */
			c = getchar();

			if (c == EOF || c == '/')
				s = 1;
		}
	}

	return c;
}