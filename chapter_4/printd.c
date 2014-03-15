/* Print an integer as a string */

#include <stdio.h>

void printd(int n);

int main() {
	int numbers[] = {-1, 4352, 352, -999, 1003};
	int i;

	for (i = 0; i < 5; i++) { 
		printd(numbers[i]);
		putchar('\n');
	}
}

void printd(int n)
{
	if (n < 0) {
		putchar('-');
		n = -n;
	}

	if (n / 10)
		printd(n / 10);

	putchar(n % 10 + '0');
}