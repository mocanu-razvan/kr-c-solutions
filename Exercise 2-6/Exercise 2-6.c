/*
Exercise 2-6 from K+R
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
Write a function setbits(x, p, n, y) that returns x with the n bits
that begin at position p set to the rightmost n bits of y, leaving
the other bits unchanged.
*/

#include <stdio.h>

int setbits(int, unsigned int, unsigned int, int);

int main()
{
	printf("%s\t\t\t\t\t%s\t%s\n", "Test", "Expected", "Actual");
	printf("%s\t\t\t\t\t%s\t%s\n", "----", "--------", "------");
	printf("%s\t%d\t%d\n", "setbits(0x12ff5678, 23, 8, 0x34)", 0x12345678, setbits(0x12ff5678, 23, 8, 0x34));
	printf("%s\t\t%d\t\t%d\n", "setbits(0xedcc, 3, 4, 0xb)", 0xedcb, setbits(0xedcc, 3, 4, 0xb));
	printf("%s\t\t%d\t\t%d\n", "setbits(0x7c0, 10, 11, 0x7e3)", 0x7e3, setbits(0x7c0, 10, 11, 0x7e3));
	return 0;
}

int setbits(int x, unsigned int p, unsigned int n, int y)
{
	int a;		/* Integer derived from x by setting to 0 the n bits that begin at position p. */
	int b;		/* Integer derived from y by setting to 0 all bits except the rightmost n ones
				and aligning them to position p. */
	a = x & ~(~(~0 << n) << (p - n + 1));
	b = (y & ~(~0 << n)) << (p - n + 1);
	x = a | b;
	return x;
}