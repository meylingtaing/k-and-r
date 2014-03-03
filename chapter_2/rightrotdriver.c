/* Write function rightrot(x, n) that returns x rotated to right n times */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

unsigned int rightrot(unsigned int x, int n);

int main (int argc, char** argv) {
	unsigned int x;
	int n;

	if (argc < 3) {
		printf("x rotation to the right n times\n");
		printf("Usage: %s x n", argv[0]);
	}

	x = strtoul(argv[1], NULL, 2);
	n = atoi(argv[2]);

	printf("%u\n", rightrot(x, n));
	return 0;
}

unsigned int rightrot(unsigned int x, int n) {
	// Grab mask from right n bits
	// Kind of cheating by using sizeof
	unsigned int rightbits = 
		(x & ~(~0 << n)) << (sizeof(unsigned int) * CHAR_BIT - (n + 1));

	return rightbits | (x >> n);
}