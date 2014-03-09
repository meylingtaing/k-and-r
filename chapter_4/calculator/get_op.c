/* getop function */
#include <ctype.h>
#include <stdio.h>

#define NUMBER '0'

int getch(void);
void ungetch(int c);

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