/* Getting a float...which returns an int but saves the value as a double */

#include <ctype.h>
#include <stdio.h>
#include <math.h>

int getch(void);
void ungetch(int);
int getfloat(double *pn);

int main() {
	double num;
	int status;

	while ((status = getfloat(&num)) != 0)
		printf("%g\n", num);

	return 0;
}

/* getint: get next integer from input into *pn */
int getfloat(double *pn)
{
	int c, sign, power;
	power = 0;

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
	if (c == '.')
		c = getch();
	for (; isdigit(c); c = getch()) {
		*pn = 10 * (*pn) + (c - '0');
		power++;
	}

	*pn *= sign;
	*pn /= pow(10, power);

	if (c != EOF)
		ungetch(c);

	return c;
}