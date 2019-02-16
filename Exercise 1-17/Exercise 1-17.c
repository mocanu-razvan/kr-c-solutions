/*
Exercise 1-17 from K+R
Copyright (c) 2019 Răzvan Mocanu

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/*
Write a program to print all input lines that are longer than 80 characters.
*/

#include <stdio.h>

#define MAX 100 /* Maximum input line length. */
#define LIMIT 80

int getline(char s[], int lim);

int main()
{
	/* total represents a line's total length. */
	int len, total;
	char line[MAX];

	len = total = 0;
	while ((len = getline(line, MAX)) > 0) {
		total = total + len;

		/* Works with arbitrarily long input lines only because LIMIT < MAX. */
		if (total > LIMIT)
			printf("%s", line);

		if (len + 1 < MAX || line[len - 1] == '\n')
			total = 0;
	}

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
