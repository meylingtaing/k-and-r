/* Simple calculator */
/* Add the modulus operator */
/* Now pressing enter peeks, and doesn't pop */

#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100	// max size of operator or operand
#define NUMBER '0'	// signal that a number was found

int getop(char opstring[]);
void push(double num);
double pop(void);
double peek(void);
void duptop(void);
void swaptop2(void);
void clear(void);

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