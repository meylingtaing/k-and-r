/* Write a function invert(x, p, n) that returns x with the n bits that begin
   at position p inverted */

#include <stdio.h>
#include <stdlib.h>

unsigned int invert(unsigned int x, int p, int n);

int main(int argc, char** argv) {
	unsigned int x;
	int p, n;

	if (argc < 4) {
		printf("x with the n bits that begin at position p inverted\n");
		printf("Usage: %s x p n\n", argv[0]);
		return -1;
	}

	x = strtoul(argv[1], NULL, 2);
	p = atoi(argv[2]);
	n = atoi(argv[3]);

	printf("%u\n", invert(x, p, n));
	return 0;
}

unsigned int invert(unsigned int x, int p, int n) {
	
	// Using XOR
	return x ^ ( ~(~0 << n) << (p+1-n) );
}