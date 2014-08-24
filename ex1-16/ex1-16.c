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

/*
 * NOTE: Reading the requirement carefuly leads me to believe the authors
 * were hinting at revising the main() function since they mention printing
 * and counting the total length of the text, operations which the getline()
 * function most certainly shouldn't do.
 *
 * In the first version I did just this, but then I observed that
 * information relating to where a line should end leaked out from
 * getline() into main().
 *
 * Reconsidering a better solution, I ended up modifying getline()
 * which leads to a clean solution that separates the concerns of
 * the functions.
 *
 * Also, it turns out it's best to include a newline character at the end of
 * the line, even if the line array is not big enough to hold the entire line,
 * because the purpose of the getline() function is to do a best effort to
 * acquire a line and its users expect lines terminated with newline characters.
 * Otherwise, unintuitive logic would have to be put in main() to determine
 * if the line contains a newline character or not.
 */

#include <stdio.h>

#define MAX 100 /* Maximum input line length. */

int getline(char s[], int lim);

int main()
{
	int len, max, total;
	char line[MAX];

	len = max = total = 0;
	while ((len = getline(line, MAX)) > 0) {
		if (len > max)
			max = len;
		total = total + len;
	}

	printf("longest: %d\n", max);
	printf("total: %d\n", total);

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
	int c, j;
	long i;

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
