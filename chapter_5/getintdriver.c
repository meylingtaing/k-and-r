/* Does not read + or - as valid number */

#include <ctype.h>
#include <stdio.h>

int getch(void);
void ungetch(int);
int getint(int *pn);

int main() {
	int num;
	int status;

	while ((status = getint(&num)) != 0)
		printf("%d\n", num);

	return 0;
}

/* getint: get next integer from input into *pn */
int getint(int *pn)
{
	int c, sign;

	// Skip whitespace
	while ( isspace(c = getch()) );

	// Check if it isn't a number
	if (!isdigit(c) && c != '+' && c!= '-') {
		ungetch(c);
		return 0;
	}

	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-')
		c = getch();

	if (!isdigit(c)) {
		ungetch(c);
		return 0;
	}

	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * (*pn) + (c - '0');
	*pn *= sign;

	if (c != EOF)
		ungetch(c);

	return c;
}