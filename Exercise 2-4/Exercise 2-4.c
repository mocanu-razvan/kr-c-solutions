﻿/*
Exercise 2-4 from K+R
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
Write an alternative version of squeeze(s1, s2) that deletes each
character in s1 that matches any character in the string s2.
*/

#include <stdio.h>

void squeeze(char[], const char[]);

int main()
{
	char s1[] = "Kernighan";
	char s2[] = "Ritchie";
	char s3[] = "Earth";
	char s4[] = "Venus";
	char s5[] = "UNIX";
	char s6[] = "LINUX";

	printf("%s\t\t\t\t%s\t%s\n", "Test", "Expected", "Actual");
	printf("%s\t\t\t\t%s\t%s\n", "----", "--------", "------");
	printf("%s\t%s\t\t", "squeeze(\"Kernighan\", \"Ritchie\")", "Krngan");
	squeeze(s1, s2); printf("%s\n", s1);
	printf("%s\t%s\t\t", "squeeze(\"Earth\", \"Venus\")", "Earth");
	squeeze(s3, s4); printf("%s\n", s3);
	printf("%s\t%s\t\t", "squeeze(\"UNIX\", \"LINUX\")", "");
	squeeze(s5, s6); printf("%s\n", s5);

	return 0;
}

void squeeze(char s1[], const char s2[])
{
	unsigned int i;		/* Current index in s1 for character not found in s2.*/
	unsigned int j;		/* Current index in s1. */
	unsigned int k;		/* Current index in s2. */

	for (i = j = 0; s1[j] != '\0'; j++) {
		for (k = 0; s2[k] != '\0' && s1[j] != s2[k]; k++)
			;
		if (s2[k] == '\0')
			s1[i++] = s1[j];
	}
	s1[i] = '\0';
}