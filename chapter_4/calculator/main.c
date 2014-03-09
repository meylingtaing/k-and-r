/* Simple calculator */
/* Add the modulus operator */

#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100	// max size of operator or operand
#define NUMBER '0'	// signal that a number was found

int getop(char opstring[]);
void push(double num);
double pop(void);

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
			case '\n':
				printf("\t%.8g\n", pop());
				break;
			default:
				printf("Error: unknown command %s\n", s);
				break;
		}
	}
	return 0;
}