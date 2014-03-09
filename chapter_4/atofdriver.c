/* Extend atof to handle scientific notation. Sorta cheating by using math. */

#include <ctype.h>
#include <math.h>
#include <stdio.h>

double atof(char s[]);

int main(int argc, char** argv) {
	if (argc < 2) {
		printf("Usage: %s floating_pt_num\n", argv[0]);
		return -1;
	}

	printf("%lf\n", atof(argv[1]));
	return 0;
}

double atof(char s[]) {
	int exp_val, power;
	double val;
	int i, sign, exp_sign;

	// Skip white spaces
	for (i = 0; isspace(s[i]); i++);

	// Sign
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	
	// Actual digits
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');

	// Decimal point
	if (s[i] == '.')
		i++;

	// Digits after decimal point
	for (power = 0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power++;
	}

	// Check for E
	if (s[i] == 'e' || s[i] == 'E')
		i++;

	// Check for sign again
	exp_sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;

	// Get a number
	for (exp_val = 0; isdigit(s[i]); i++)
		exp_val = 10 * exp_val + (s[i] - '0');
	exp_val *= exp_sign;
	exp_val = pow(10, power-exp_val);

	//printf("Exp power: %d\n", exp_val);

	return sign * val / exp_val;
}