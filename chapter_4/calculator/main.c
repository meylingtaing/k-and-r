/* Simple calculator */
/* Add the modulus operator */
/* Now pressing enter peeks, and doesn't pop, and commands for clear and 
   swap and repeat operand */
/* Add sin, exp, and pow */
/* Add commands for handling variables */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXOP 100	// max size of operator or operand
#define NUMBER '0'	// signal that a number was found
#define SIN '1'
#define COS '2'
#define TAN '3'
#define EXP '4'
#define POW '5'
#define VARIABLE '6'
#define ASSIGN '7'

int getop(char opstring[]);
void push(double num);
double pop(void);
double peek(void);
void duptop(void);
void swaptop2(void);
void clear(void);

double variables[26] = {0};

// But it's a polish calculator
int main() {
	
	int type;
	double op2;		// For div and sub, we need to do the operation backwards
	char s[MAXOP];

	while ( (type=getop(s)) != EOF ) {
		switch (type) {
			case NUMBER:
				push(atof(s));
				break;
			case VARIABLE:
				push(variables[s[0] - 'A']);
				break;
			case ASSIGN:
				if (s[0] < 'A' || s[0] > 'Z')
					printf("Error: Not a proper variable name\n");
				else
					variables[s[0] - 'A'] = pop();
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				if (op2 != 0.0)
					push(pop() / op2);
				else
					printf("Error: Zero division\n");
				break;
			case '%':
				op2 = pop();
				if (op2 != 0.0)
					push((int)pop() % (int)op2);
				else printf("Error: Zero division with modulus\n");
				break;
			case SIN:
				push(sin(pop()));
				break;
			case COS:
				push(cos(pop()));
				break;
			case TAN:
				// Not bothering to worry about multiples of pi/2
				push(tan(pop()));
				break;
			case EXP:
				push(exp(pop()));
				break;
			case POW:
				op2 = pop();
				push(pow(pop(), op2));
				break;
			case 'd':
				// d for duplicate
				duptop();
				break;
			case 's':
				// s for swap
				swaptop2();
				break;
			case 'c':
				// c for clear
				clear();
				break;
			case '\n':
				printf("\t%.8g\n", peek());
				break;
			default:
				printf("Error: unknown command %s\n", s);
				break;
		}
	}
	return 0;
}