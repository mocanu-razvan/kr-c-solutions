/*
 * Exercise 1-24 from K+R
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
 * Write a program to check a C program for rudimentary syntax errors like
 * unmatched parentheses, brackets and braces. Don't forget about quotes, both
 * single and double, escape sequences, and comments. (This program is hard if
 * you do it in full generality.)
 */

#include <stdio.h>

int getcharn(void);
int quote(int);
int comment(void);
void check(int);

int nl;		/* The current line number. */
int nc;		/* The current column number within the current line. */
int npar;	/* The current number of unmatched open parentheses. */
int nbrk;	/* The current number of unmatched open brackets. */
int nbrc;	/* The current number of unmatched open braces. */

int main()
{
	int c;

	nl = 1;
	/*
	 * Since the check is done after reading a character, the column number
	 * will indicate the next character when an error is encountered.
	 * To display the column number of the unmatched parenthesis, bracket or
	 * brace we can either always substract 1 when printing the error message,
	 * or start from 0.
	 */
	nc = 0;
	npar = nbrk = nbrc = 0;

	c = getcharn();

	while (c != EOF) {
		/* Is it the beginning of a character or string constant? */
		if (c == '\'' || c == '"')
			c = quote(c);
		/* Is it the beginning of a comment? */
		else if (c == '/') {
			/* Look at the next character to confirm. */
			if ((c = getcharn()) != EOF) {
				if (c == '*')
					c = comment();
				else
					check(c);
			}
		} else
			check(c);

		if (c != EOF)
			c = getcharn();
	}

	/*
	 * Do a final check on the counters and
	 * print appropriate error messages.
	 */
	if (npar > 0)
		printf("%d:%d: unmatched open parentheses \"(\": %d\n", nl, nc, npar);
	if (nbrk > 0)
		printf("%d:%d: unmatched open brackets \"[\": %d\n", nl, nc, nbrk);
	if (nbrc > 0)
		printf("%d:%d: unmatched open braces \"{\": %d\n", nl, nc, nbrc);

	return 0;
}

/*
 * Returns the next character from the standard input stream while
 * increasing the current line and column numbers as appropriate.
 */
int getcharn(void)
{
	int c;

	c = getchar();

	if (c == '\n') {
		++nl;
		nc = 0;
	} else if (c != EOF)
		++nc;

	return c;
}

/*
 * Checks for unmatched parentheses, brackets and braces.
 * If any of the counters becomes negative it means there is
 * an unmatched closed parenthesis, bracket or, respectivelly, brace.
 * In this case, the function prints an appropriate error message.
 * The counters are allowed to be positive, since they might return to 0 later.
 */
void check(int c)
{
	if (c == '(')
		++npar;
	else if (c == ')')
		--npar;
	else if (c == '[')
		++nbrk;
	else if (c == ']')
		--nbrk;
	else if (c == '{')
		++nbrc;
	else if (c == '}')
		--nbrc;

	if (npar < 0) {
		printf("%d:%d: unmatched closed parenthesis ')'\n", nl, nc);
		npar = 0;
	}
	if (nbrk < 0) {
		printf("%d:%d: unmatched closed bracket ']'\n", nl, nc);
		nbrk = 0;
	}
	if (nbrc < 0) {
		printf("%d:%d: unmatched closed brace '}'\n", nl, nc);
		nbrc = 0;
	}
}

/*
 * Skips over the characters of a character or string constant.
 * Correctly handles possible escape sequences.
 */
int quote(int q)
{
	int c;

	c = getcharn();

	/* Read until the end of the constant. */
	while (c != EOF && c != q) {
		/* Is it the beginning of an escape sequence? */
		if (c == '\\')
			/*
			 * Skip the next character.
			 * The escape sequence might escape the quote character.
			 * If this would be left unhandled, it would be mistaken
			 * for the end of the constant.
			 */
			c = getcharn();

		if (c != EOF)
			c = getcharn();
	}

	return c;
}

/* Skips over the characters of a comment. */
int comment(void)
{
	int c;
	int s;	/* Flag to indicate the end of the comment. */

	s = 0;

	while (s != 1) {
		/* Read until the beginning of the end of the comment. */
		while ((c = getcharn()) != EOF && c != '*')
			;

		if (c == EOF)
			s = 1;
		else {
			/* Read the next character to confirm the end. */
			c = getcharn();

			if (c == EOF || c == '/')
				s = 1;
		}
	}

	return c;
}