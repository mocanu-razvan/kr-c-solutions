/* Exercise 1-19 from K+R
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
 * Write a function reverse(s) that reverses the character string s. Use it to
 * write a program that reverses its input a line at a time.
 */

#include <stdio.h>

#define MAX 100 /* Maximum input line length. */

int getline(char s[], int lim);
void reverse(char s[], int len);

int main()
{
	int len;
	char line[MAX];

	len = 0;
	while ((len = getline(line, MAX)) > 0) {
		reverse(line, len);
		printf("%s", line);
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

/* Reverses a character array in place. */
void reverse(char s[], int len) {
	char c;
	int i;

	/* Preserve the \n if present. */
	if (s[len - 1] == '\n')
		--len;

	/* Skip the \0 or \n character. */
	--len;
	i = 0;

	/* Reverse the character array in place. */
	while (i < len) {
		c = s[i];
		s[i] = s[len];
		s[len] = c;

		++i;
		--len;
	}
}
