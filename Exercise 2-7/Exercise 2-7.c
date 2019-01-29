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
Write a function invert(x, p, n) that returns x with the n bits that
begin at position p inverted (i.e. 1 changed into 0 and vice versa),
leaving the others unchanged.
*/

#include <stdio.h>

int invert(int, unsigned int, unsigned int);

int main()
{
	printf("%s\t\t\t\t%s\t%s\n", "Test", "Expected", "Actual");
	printf("%s\t\t\t\t%s\t%s\n", "----", "--------", "------");
	printf("%s\t%d\t%d\n", "invert(0x12cc5678, 23, 8)", 0x12335678, invert(0x12cc5678, 23, 8));
	printf("%s\t\t%d\t\t%d\n", "invert(0xa53c, 15, 16)", 0x5ac3, invert(0xa53c, 15, 16));
	printf("%s\t\t%d\t\t%d\n", "invert(0xff00, 15, 16)", 0xff, invert(0xff00, 15, 16));
	printf("%s\t\t%d\t\t%d\n", "invert(0xfe7f, 8, 2)", 0xffff, invert(0xfe7f, 8, 2));
	return 0;
}

int invert(int x, unsigned int p, unsigned int n)
{
	int a;		/* Integer derived from x by setting to 0 the n bits that begin at position p. */
	int i;		/* Integer derived from x by inverting the n bits that begin at position p and
					setting all the others to 0. */
	a = x & ~(~(~0 << n) << (p - n + 1));
	i = (~((x >> (p - n + 1)) & ~(~0 << n)) & ~(~0 << n)) << (p - n + 1);
	x = a | i;
	return x;
}