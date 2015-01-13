/* Exercise 1-21 from K+R
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
 * Write a program `entab` that replaces strings of blanks by the minimum
 * number of tabs and blanks to achieve the same spacing. Use the same tab
 * stops as for `detab`. When either a tab or a single blank would suffice to
 * reach a tab stop, which should be given preference?
 */

#include <stdio.h>

#define N 8 /* Size of a tab stop. */

int main() {
	int c;
	int n; /* Remaining number of characters until the next tab stop. */
	int s; /* Number of consecutive spaces. */

	n = N;
	s = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			++s;
			--n;
			if (n == 0) {
				/*
				 * Most simple is to give prefernce to a tab stop
				 * when `s == 1`.
				 */
				putchar('\t');
				s = 0;
				n = N;
			}
		} else {
			if (c != '\t' && s > 0)
				while (s > 0) {
					putchar(' ');
					--s;
				}
			/* Discard accumulated spaces if `c` is a tab character. */
			s = 0;
			if (c == '\t' || c == '\n')
				n = N;
			else {
				--n;
				if (n == 0)
					n = N;
			}
			putchar(c);
		}
	}
	return 0;
}