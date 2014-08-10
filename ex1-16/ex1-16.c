/*
 * Exercise 1-16 from K+R
 * Copyright � 2014 Răzvan Mocanu
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

#define MAX 1000 /* Maximum input line length. */

int getline(char s[], int lim);

main()
{
	int len;
	long mlen, max, total;
	char line[MAX];

	mlen = len = max = total = 0;
	while ((len = getline(line, MAX)) > 0) {
		mlen = mlen + len;
		if (len != MAX - 1 || line[MAX - 1] == '\n') {
			if (mlen > max)
				max = mlen;
			total = total + mlen;
			mlen = 0;
		}
	}
	if (total > 0) {
		printf("longest: %d\n", max);
		printf("total: %d\n", total);
	}

	return 0;
}

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
