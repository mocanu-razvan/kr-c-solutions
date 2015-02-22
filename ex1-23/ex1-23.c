/* Exercise 1-23 from K+R
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
 * Write a program to remove all comments from a C program. Don't forget
 * to handle quoted strings and character constants properly. C comments
 * don't nest.
 */

#include <stdio.h>

void unget(int);
int next(void);
void quote(int);
void comment(void);

int b;		/* Input stream buffer. */

int main()
{
	int c;

	/* Initialize the stream buffer. */
	b = 0;

	while ((c = next()) != EOF)
		/* Is it the beginning of a character or string constant? */
		if (c == '\'' || c == '"')
			quote(c);
		/* Is it the beginning of a comment? */
		else if (c == '/') {
			/* Look at the next character to confirm. */
			if ((c = getchar()) != EOF) {
				if (c == '*')
					comment();
				else {
					/* Put the read character back. */
					unget(c);
					/* Print the previous character. */
					putchar('/');
				}
			}
		} else
			putchar(c);

	return 0;
}

/*
 * Puts a character back in the stream so that it is returned
 * by the next call to `next()`.
 */
void unget(int c)
{
	b = c;
}

/*
 * Returns the next character from the standard input stream.
 * If a character has been put back into the stream using a
 * call to `unget()` then that character is returned and the
 * buffer is cleared. Otherwise, `getchar()` is used to obtain
 * the next character in the stream.
 */
int next(void)
{
	int c;

	if (b != 0) {
		c = b;
		b = 0;
	} else
		c = getchar();

	return c;
}

/*
 * Parses a character or string constant. Takes into
 * account the existence of escape sequences. Comments
 * cannot be placed inside these constants so everything
 * is output.
 */
void quote(int q)
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
}

/*
 * Parses a comment. Comments cannot be nested.
 * Does not output anything inside, effectively
 * removing the comment from the input stream.
 */
void comment(void)
{
	int c;
	int s;	/* Flag to indicate the end of the comment. */

	s = 0;

	while (s != 1) {
		/* Read until the beginning of the end of the comment. */
		while ((c = next()) != EOF && c != '*')
			;

		if (c == EOF)
			s = 1;
		else {
			/* Read the next character to confirm the end. */
			c = getchar();

			if (c == '/')
				s = 1;
			else
				unget(c);
		}
	}
}