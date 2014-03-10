/* getop function */
#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define NUMBER '0'
#define SIN '1'
#define COS '2'
#define TAN '3'
#define EXP '4'
#define POW '5'
#define VARIABLE '6'
#define ASSIGN '7'

int getch(void);
int ungetch(int c);
void ungets(char s[]);

/* Be able to deal with negative numbers */

// getop: get next operator or numeric operand
int getop(char s[]) {
	int i, c;
	char sign;

	// Get past all leading whitespace
	while ( (s[0] = c = getch()) == ' ' || c == '\t');

	s[1] = '\0';

	// Check for + or -
	if (c == '-' || c == '+') {
		sign = c;
		c = getch();
		ungetch(c);
		if (!isdigit(c) && c != '.')
			return sign;
	}

	// Check for variable to use
	if (isupper(c)) {
		return VARIABLE;
	}

	// Check for variable assignment
	if (c == '=') {
		s[0] = getch();
		return ASSIGN;
	}

	// Check for sin, cos, tan, exp, pow
	// Grab three letters
	if (islower(c)) {
		s[1] = getch();
		if (s[1] == '\n') {
			ungetch(s[1]);
			return c;
		}
		s[2] = getch();
		if (strncmp(s, "sin", 3) == 0)
			return SIN;
		else if (strncmp(s, "cos", 3) == 0)
			return COS;
		else if (strncmp(s, "tan", 3) == 0)
			return TAN;
		else if (strncmp(s, "exp", 3) == 0)
			return EXP;
		else if (strncmp(s, "pow", 3) == 0)
			return POW;

		s[3] = 0;
		ungets(s + 1);
	}

	// Return whatever c is if it's not a number
	if (!isdigit(c) && c != '.')
		return c;

	// Get integer part
	i = 0;
	if (isdigit(c))
		while ( isdigit(s[++i] = c = getch()) );

	// Get fractional part
	if (c == '.')
		while ( isdigit(s[++i] = c = getch()) );

	s[i] = '\0';
	if (c != EOF)
		ungetch(c);

	return NUMBER;
}