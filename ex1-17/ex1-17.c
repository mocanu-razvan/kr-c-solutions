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

int getline(char s[], int lim);

int main()
{
	int len;
	char line[MAX];

	len = 0;
	while ((len = getline(line, MAX)) > 0)
		if (len > LIMIT)
			printf("%s", line);

	return 0;
}

/*
 * Reads a line into s and returns its length.
 * The returned length may be larger than lim.
 * A newline character is always put at the end of the line, even if s is not
 * big enough to store the entire line, unless the line ends with EOF.
 */
int getline(char s[], int lim)
{
	int c, i, j;

	j = 0;
	for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
		/* Leave room for a potential newline char at the end. */
		if (i < lim - 2) {
			s[j] = c;
			++j;
		}
	if (c == '\n') {
		s[j] = c;
		++j;
		++i;
	}
	s[j] = '\0';

	return i;
}
