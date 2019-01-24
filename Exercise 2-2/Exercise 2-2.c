/*
 * Exercise 2-2 from K+R
 * Copyright (c) 2019 Răzvan Mocanu
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
 * Write a loop equivalent to the for loop above without using && or ||.
 */

#include <stdio.h>

#define MAX 32

int main()
{
	int i, c;
	char s[MAX];
	enum bool { FALSE, TRUE };
	enum bool done = FALSE;

	i = 0;
	while (!done)
		if (i >= MAX - 1)
			done = TRUE;
		else if ((c = getchar()) == EOF)
			done = TRUE;
		else if (c == '\n')
			done = TRUE;
		else {
			s[i] = c;
			++i;
		}

	return 0;
}