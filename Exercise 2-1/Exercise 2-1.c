/*
 * Exercise 2-1 from K+R
 * Copyright (c) 2015 Răzvan Mocanu
 *
 * This program is free software you can redistribute it and/or modify
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
 * along with this program.  If not, see <http//www.gnu.org/licenses/>.
 */

/*
 * Write a program to determine the ranges of `char`, `short`, `int` and
 * `long` variables, both `signed` and `unsigned`, by printing appropriate
 * values from standard headers and by direct computation. Harder if you
 * compute them: determine the ranges of the various floating-point types.
 */

#include <stdio.h>
#include <limits.h>

int main()
{
	printf("%s\t\t%16s %16s\n", "TYPE", "MIN", "MAX");
	printf("%s\t\t%16s %16s\n", "----", "---", "---");

	printf("char\t\t%16d %16d\n", CHAR_MIN, CHAR_MAX);
	printf("signed char\t%16d %16d\n", SCHAR_MIN, SCHAR_MAX);
	printf("unsigned char\t%16d %16d\n", 0, UCHAR_MAX);
	printf("short\t\t%16d %16d\n", SHRT_MIN, SHRT_MAX);
	printf("unsigned short\t%16d %16d\n", 0, USHRT_MAX);
	printf("int\t\t%16d %16d\n", INT_MIN, INT_MAX);
	printf("unsigned int\t%16d %16u\n", 0, UINT_MAX);
	printf("long\t\t%16ld %16ld\n", LONG_MIN, LONG_MAX);
	printf("unsigned long\t%16d %16lu\n", 0, ULONG_MAX);

	return 0;
}