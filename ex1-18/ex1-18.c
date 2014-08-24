/* Exercise 1-18 from K+R
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
 * Write a program to remove trailing blanks and tabs from each line of input,
 * and to delete entirely blank lines.
 */

#include <stdio.h>

#define MAX 100 /* Maximum input line length. */

int getline(char s[], int lim);
int trimline(char s[], int lim);

int main()
{
	int len;
	char line[MAX];

	len = 0;
	while ((len = getline(line, MAX)) > 0) {
		if ((len = trimline(line, len)) > 0)
			printf("%s\n", line);
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

/* Removes traling blanks and tabs from a line and returns its new length. */
int trimline(char s[], int len) {
	while (len > 0 &&
			(s[len - 1] == ' ' || s[len - 1] == '\t' || s[len - 1] == '\n'))
		--len;
	s[len] = '\0';
	return len;
}
