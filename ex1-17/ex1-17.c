/*
 * Exercise 1-17 from K+R
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
 * Write a program to print all input lines that are longer than 80 characters.
 */

#include <stdio.h>

#define MAX 100 /* Maximum input line length. */
#define LIMIT 80

long getline(char s[], int lim);

main()
{
	long len;
	char line[MAX];

	len = 0;
	while ((len = getline(line, MAX)) > 0) {
		if (len > LIMIT) {
			printf("%s", line);

			/*
			 * The returned length excludes newline characters.
			 * Print a newline for nice output formatting when it is impossible
			 * for the printed line to have contained a newline character.
			 * If a line contains a newline character then its length must be
			 * at most MAX - 2 since the last 2 characters must be in this case
			 * \n and \0.
			 */
			if (len > MAX - 2)
				printf("\n");
		}
	}

	return 0;
}

/* Stores as much as possible into s and returns entire line length. */
long getline(char s[], int lim)
{
	int c, i;
	long j;

	i = 0;
	for (j = 0; (c = getchar()) != EOF && c != '\n'; ++j)
		if (i < lim - 1) {
			s[i] = c;
			++i;
		}
	if (c == '\n' && i < lim - 1) {
		s[i] = c;
		++i;
	}
	s[i] = '\0';

	return j;
}
