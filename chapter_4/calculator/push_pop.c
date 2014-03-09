/* Push and pop operations */

#include <stdio.h>

#define MAXVAL 100	// max depth of value stack

int sp = 0;			// Stack pointer --  next free stack position
double val[MAXVAL];	// Value stack

// push: push f onto value stack
void push(double f) {
	if (sp < MAXVAL) { 
		//printf("Pushing value %g\n", f);
		val[sp++] = f;
	}
	else
		printf("Error: stack is full, can't push %g\n", f);
}

// pop: pop and return top value from stack
double pop(void) {
	if (sp > 0)
		return val[--sp];
	else {
		printf("Error: stack empty\n");
		return 0.0;
	}
}