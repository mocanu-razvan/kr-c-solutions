/*
 * Exercise 1-9 from K+R
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
 * Write a program to copy its input to its output, replacing each string of
 * one or more blanks by a single blank.
 */

#include <stdio.h>

/*
 * When encountering a space it only sets a flag variable to 1 without
 * printing anything. Whenever a non-blank character is instead encountered
 * it checks if the flag is set, thus inferring that one or more spaces
 * have occurred before it. In this case it only prints one blank character,
 * effectively compressing strings of one or more blanks to a single one.
 */
main()
{
	int c, b;

	/* Flag for indicating that one or more blanks were encountered. */
	b = 0;

	while ((c = getchar()) != EOF) {
		if (c != ' ') {
			if (b == 1) {
				putchar(' ');
				/* Reset the flag. */
				b = 0;
			}
			putchar(c);
		}
		if (c == ' ')
			b = 1;
	}
}
