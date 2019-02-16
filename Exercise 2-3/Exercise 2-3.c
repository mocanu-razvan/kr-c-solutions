/*
Exercise 2-3 from K+R
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
Write a function htoi(s), which converts a string of hexadecimal
digits (including an optional 0x or 0X) into its equivalent integer
value. The allowable digits are 0 through 9, a through f, and A
through F.
*/

#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define FALSE 0
#define TRUE 1

unsigned long htoi(const char[]);

int main()
{
	printf("%s\t\t%s\t%s\n", "Test", "Expected", "Actual");
	printf("%s\t\t%s\t%s\n", "----", "--------", "------");
	printf("%s\t\t%ld\t\t%ld\n", "0x07e3", 2019L, htoi("0x07e3"));
	printf("%s\t\t%ld\t\t%ld\n", "0XFF", 255L, htoi("0XFF"));
	printf("%s\t\t%ld\t\t%ld\n", "07e3", 2019L, htoi("07e3"));
	printf("%s\t\t%ld\t\t%ld\n", "0x07OK", 7L, htoi("0x07OK"));
	printf("%s\t\t%ld\t\t%ld\n", "X1234", 0L, htoi("X1234"));
	printf("%s\t%ld\t\t%ld\n", "0xffffffff00", -256L, htoi("0xffffffff00"));

	return 0;
}

unsigned long htoi(const char s[])
{
	const unsigned int l = strlen(s);
	unsigned int i;		/* Current index in input string. */
	unsigned char d;	/* Integer value of current hexadecimal digit. */
	unsigned long n;	/* Integer result of conversion. */
	char h;				/* Flag to indicate if digit is hexadecimal. */

	i = 0;
	if (l > 1 && s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
		i = 2;

	n = 0;
	h = TRUE;
	for (; i < l && h; ++i) {
		if (isdigit(s[i]))
			d = s[i] - '0';
		else if (s[i] >= 'a' && s[i] <= 'f')
			d = s[i] - 'a' + 10;
		else if (s[i] >= 'A' && s[i] <= 'F')
			d = s[i] - 'A' + 10;
		else
			h = FALSE;
		if (h)
			n = n * 16 + d;
	}

	/*
		Depending on the length of s and the number of bits for the long
		data type on the machine, n might overflow. In this case, the
		result will be incorrect.
	*/
	return n;
}