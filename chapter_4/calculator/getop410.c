/* Contains the getop function for getting an operator/operand for calculator.
   I'm cheating and using pointers */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define BUFF 100	// Max length of line

// Signal that one of these ops was found
#define NUMBER 		'0'
#define SIN 		'1'
#define COS 		'2'
#define TAN 		'3'
#define EXP 		'4'
#define POW 		'5'
#define VARIABLE 	'6'
#define ASSIGN 		'7'

char line[BUFF] = {0};
int i = 0;

/* getline: get line into s, return length */
int getline_stdin(char s[], int lim) {
	int c, i;

	i = 0;
	while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
		s[i++] = c;

	if (c == '\n')
		s[i++] = c;

	s[i] = 0;
	return i;
}

/* getop: put operator/operand into s
   s is only used if NUMBER is returned */
int getop(char s[]) {
	int j;

	// Number is positive by default
	s[0] = '+';
	
	// If we've hit the end of the line, get a new one
	if (line[i] == 0) {
		if (getline_stdin(line, BUFF) == 0)
			return EOF;
		i = 0;
	}

	// Get past all leading whitespace
	while (line[i] == ' ' || line[i] == '\t')
		i++;

	// Check for + or -
	if (line[i] == '-' || line[i] == '+') {
		char sign = s[0] = line[i++];

		// Next character must be digit or . to be a number
		if (!isdigit(line[i]) && line[i] != '.') { 
			//printf("sign = %c, i = %d\n", sign, i);
			return sign;
		}
	}

	// Check for variable to use
	if (isupper(line[i])) {
		s[0] = line[i++];
		return VARIABLE;
	}

	// Check for variable assignment
	if (line[i] == '=') {
		s[0] = line[++i];	// I don't like how I did this.
		i++;
		return ASSIGN;
	}

	// Check for sin, cos, tan, exp, pow
	if (strncmp(&line[i], "sin", 3) == 0) {
		i += 3;
		return SIN;
	}
	if (strncmp(&line[i], "cos", 3) == 0) {
		i += 3;
		return COS;
	}
	if (strncmp(&line[i], "tan", 3) == 0) {
		i += 3;
		return TAN;
	}
	if (strncmp(&line[i], "pow", 3) == 0) {
		i += 3;
		return POW;
	}
	if (strncmp(&line[i], "exp", 3) == 0) {
		i += 3;
		return EXP;
	}

	// Return whatever if it's not a number
	if (!isdigit(line[i]) && line[i] != '.')
		return line[i++];

	// Get integer part
	j = 1;
	if (isdigit(line[i])) {
		while ( isdigit(s[j++] = line[i++]) );
	}

	// Get fractional part
	if (line[i] == '.') {
		while ( isdigit(s[j++] = line[i++]) );
	}

	s[j] = 0;
	return NUMBER;
}