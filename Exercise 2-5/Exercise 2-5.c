/*
Exercise 2-5 from K+R
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
Write the function any(s1, s2), which returns the first location in
a string s1 where any character from the string s2 occurs, or -1 if s1
contains no characters from s2. (The standard library function strpbrk
does the same job but returns a pointer to the location.)
*/

#include <stdio.h>

int any(const char[], const char[]);

void main()
{
	printf("%s\t\t\t\t%s\t%s\n", "Test", "Expected", "Actual");
	printf("%s\t\t\t\t%s\t%s\n", "----", "--------", "------");
	printf("%s\t\t\t%d\t\t%d\n", "any(\"H2O\", \"H\")", 0, any("H2O", "H"));
	printf("%s\t%d\t\t%d\n", "any(\"Kernighan\", \"Ritchie\")", 1, any("Kernighan", "Ritchie"));
	printf("%s\t\t%d\t\t%d\n", "any(\"Linux\", \"Hex\")", 4, any("Linux", "Hex"));
	printf("%s\t%d\t\t%d\n", "any(\"Vivaldi\", \"Schoenberg\")", -1, any("Vivaldi", "Schoenberg"));

	return 0;
}

int any(const char s1[], const char s2[])
{
	int i;		/* Current index in s1. */
	int j;		/* Current index in s2. */

	for (i = 0; s1[i] != '\0'; i++)
		for (j = 0; s2[j] != '\0'; j++)
			if (s1[i] == s2[j])
				return i;

	return -1;
}
