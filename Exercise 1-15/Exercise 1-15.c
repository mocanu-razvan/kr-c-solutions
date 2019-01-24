/*
 * Exercise 1-15 from K+R
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
 * Rewrite the temperature conversion program of Section 1.2 to use a function
 * for conversion.
 */

#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

double celsius(int fahr);

main()
{
	int fahr;

	for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
		printf("%3d %6.1f\n", fahr, celsius(fahr));

	return 0;
}

/*
 * Converts temperatures from Fahrenheit to Celsius.
 */
double celsius(int fahr) {
	return (5.0 / 9.0) * (fahr - 32);
}
