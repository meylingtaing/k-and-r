/* Write the program expr, which evaluates a reverse Polish expression from
   the command line. Only dealing with integers */

#include <stdio.h>

#define NUMBER 	'0'
#define SIZE 	100

int stack[SIZE];
int sp = 0;

void push(int n);
int pop();

int main(int argc, char **argv)
{
	if (argc < 2) {
		printf("Usage: %s polish_expression\n", argv[0]);
		return -1;
	}

	while (*++argv) {
		int op1;
		switch(get_op(argv[0])) {
			case '+':
				push(pop() + pop());
				break;
			case '-':
				op1 = pop();
				push(op1 - pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '/':
				op1 = pop();
				push(op1 / pop());
				break;
			case NUMBER:
				push(atoi(argv[0]));
				break;
			default:
				printf("Did not recognize %s\n", argv[0]);
				break;
		}
	}

	printf("\t%d\n", pop());
	return 0;
}

void push(int n)
{
	if (sp < SIZE)
		stack[sp++] = n;
	else
		printf("Error: stack is full\n");
}

int pop()
{
	if (sp > 0)
		return stack[--sp];
	else
		printf("Error: stack is empty\n");

	return 0;
}

int get_op(char input[])
{
	if (input[0] == '+' || input[0] == '-') {
		if (isdigit(input[1]))
			return NUMBER;
	}

	if (isdigit(input[0]))
		return NUMBER;
	else
		return input[0];
}