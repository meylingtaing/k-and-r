/* Push and pop operations */
/* Add commands to print out top element of stack without popping it, to 
   duplicate it, and to swap the top two elements. Also clear the stack */

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

// peek: look at top element of stack
double peek(void) {
	if (sp > 0)
		return val[sp - 1];
	else {
		printf("Stack empty\n");
		return 0.0;
	}
}

void duptop(void) {
	if (sp > 0 && sp < MAXVAL) {
		push(peek());
	}
	else
		printf("Error: Stack is either empty or full");
}

void swaptop2(void) {
	double top1, top2;

	if (sp > 1) {
		top1 = pop();
		top2 = pop();
		push(top1);
		push(top2);
	}
	else
		printf("Error: Stack contains less than 2 elements\n");
}

void clear(void) {
	sp = 0;
}