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

#define NONE 0
#define CHAR 1 			/* Inside a character constant. */
#define STR 2 			/* Inside a string constant. */
#define COMMENT 3		/* Inside a comment. */
#define START 4			/* At the start of a comment, i.e. after `/` & `*`. */
#define END 5			/* At the end of a comment, i.e. after `*` & `/`. */

int main()
{
	int c;
	int p;	/* The previous character. */
	int s;	/* The state. */
	int x;	/* Equals 1 if `c` is part of an escape sequence, 0 otherwise. */

	p = x = 0;
	s = NONE;

	while ((c = getchar()) != EOF) {
		if (x == 1)
			x = 0;
		else if (p == '\\')
			x = 1;

		switch (c) {
			case '\'':
				/*
				 * Start or end of a character constant, unless we are inside
				 * a comment, string constant or part of an escape sequence.
				 */
				if (s == COMMENT || s == STR || x == 1)
					break;
				if (s == CHAR)
					s = NONE;
				else 
					s = CHAR;
				break;
			case '"':
				/*
				 * Start or end of a string constant, unless we are inside
				 * a comment, character constant or part of an escape sequence.
				 */
				if (s == COMMENT || s == CHAR || x == 1)
					break;
				if (s == STR)
					s = NONE;
				else 
					s = STR;
				break;
			case '/':
				/*
				 * The end of a comment only if the previous character is
				 * `*` and we are not outside of a comment, inside a string or
				 * character constant.
				 */
				if (s != COMMENT || s == STR || s == CHAR || p != '*')
					break;
				s = END;
				break;
			case '*':
				/*
				 * The start of a comment only if the previous character is
				 * `/` and we aren't inside of a comment, a string or
				 * character constant.
				 */
				if (s == COMMENT || s == STR || s == CHAR || p != '/')
					break;
				s = START;
				break;
		}

		if (s == END) {
			/* End a comment .*/
			s = NONE;
			p = 0;
		} else if (s == START) {
			/* Start a comment. */
			s = COMMENT;
			p = 0;
		} else {
			if (s != COMMENT) {
				/* Only print if we are outside of a comment. */
				if (p == '/')
					/*
					 * `/` characters are not printed when encoutered to
					 * determine if they are part of a comment starting or
					 * ending sequence.
					 * Since we have determined the previous such character
					 * was not part of a comment starting sequence in this case,
					 * then print it.
					 */
					putchar('/');
				/*
				 * Don't print `/` characters since they might be part of a
				 * comment starting sequence. If this proves to be false,
				 * it will be printed in the next iteration, as explained
				 * in the comment above.
				 */
				if (c != '/')
					putchar(c);
			}
			p = c;
		}
	}

	return 0;
}