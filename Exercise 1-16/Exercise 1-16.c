/*
 * Exercise 1-16 from K+R
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
 * Revise the main routine of the longest-line program so it will correctly
 * print the length of arbitrary long input lines, and as much as possible of
 * the text.
 */

#include <stdio.h>

#define MAX 100 /* Maximum input line length. */

int getline(char s[], int lim);

int main()
{
	int len, max;
	int total; /* Total length of a line. */
	int text; /* Total length of the text. */
	char line[MAX];

	len = total = max = text = 0;
	while ((len = getline(line, MAX)) > 0) {
		total = total + len;
		text = text + len;

		if (len + 1 < MAX || line[len - 1] == '\n') {
			if (total > max)
				max = total;
			total = 0;
		}
	}

	printf("longest: %d\n", max);
	printf("total: %d\n", text);

	return 0;
}

/* Reads a line into s and returns its length. */
int getline(char s[], int lim)
{
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;

	if (c == '\n') {
		s[i] = c;
		++i;
	}

	s[i] = '\0';

	return i;
}
