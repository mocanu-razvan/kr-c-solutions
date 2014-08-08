/*
 * Exercise 1-12 from K+R
 * Copyright © 2013 Rãzvan Mocanu
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
 * Write a program that prints its input one word per line.
 */

#include <stdio.h>

#define IN 1 /* Inside a word. */
#define OUT 0 /* Outside a word. */

main()
{
	int c, state;

	state = OUT;
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') {
			if (state == IN) {
				state = OUT;
				/*
				 * Replace the first whitespace character that marks a
				 * transition from inside a word to outside one with a new
				 * line. Note that other whitespace characters outside any word
				 * are discarded.
				 */
				putchar('\n');
			}
		} else {
			if (state == OUT)
				state = IN;
			/* Print any non-whitespace character. */
			putchar(c);
		}
	}
}
