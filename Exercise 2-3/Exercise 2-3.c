/*
 * Exercise 2-3 from K+R
 * Copyright (c) 2017 Răzvan Mocanu
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
 * Write a function htoi(s), which converts a string of hexadecimal
 * digits (including an optional 0x or 0X) into its equivalent integer
 * value. The allowable digits are 0 through 9, a through f, and A
 * through F.
 */

#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main() {}

long htoi(const char s[]) {
	const unsigned int l = strlen(s);
	unsigned int i, d;
	long n;

	i = 0;
	if (l > 1 && s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
		i = 2;

	n = 0;
	while (i < l) {
		if (s[i] >= '0' && s[i] <= '9')
			d = s[i] - '0';
		else if (s[i] >= 'a' && s[i] <= 'f')
			d = s[i] - 'a' + 10;
		else if (s[i] >= 'A' && s[i] <= 'F')
			d = s[i] - 'A' + 10;
		else
			return -1;
		n = n * 16 + d;
		++i;
	}

	return n;
}