/*
 * Exercise 1-14 from K+R
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
 * Write a program to print a histogram of the frequencies of different
 * characters in its input.
 */

#include <stdio.h>

#define MAX 256 /* Maximum counted characters. */

main()
{
	int freqs[MAX], c;

	for (c = 0; c < MAX; ++c)
		freqs[c] = 0;

	while ((c = getchar()) != EOF)
		if (c >= 0 && c < MAX)
			++freqs[c];

	for (c = 0; c < MAX; ++c)
		if (freqs[c] > 0) {
			printf("%1c (%3d) %3d: ", c, c, freqs[c]);
			for (; freqs[c] > 0; --freqs[c])
				printf("#");
			printf("\n");
		}
}
