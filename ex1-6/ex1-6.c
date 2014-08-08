/*
 * Exercise 1-6 from K+R
 * Copyright © 2013 Rãzvan Mocanu
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
 * Verify that the expression getchar() != EOF is 0 or 1.
 */

#include <stdio.h>

main()
{
	int c;

	while (c = getchar() != EOF)
		printf("%d", c);

	printf("%d\n", c);
}
