/* getop function */
#include <ctype.h>
#include <stdio.h>

#define NUMBER '0'

int getch(void);
void ungetch(int c);

// getop: get next operator or numeric operand
int getop(char s[]) {
	int i, c;

	// Get past all leading whitespace
	while ( (s[0] = c = getch()) == ' ' || c == '\t');

	// Return whatever c is if it's not a number
	s[1] = '\0';
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
		ungetch(c);;

	return NUMBER;
}