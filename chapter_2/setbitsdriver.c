/* Write function setbits(x, p, n, y) that returns x with n bits that begin at
   position p set to the rightmost n bits of y, leaving other bits unchanged */

#include <stdlib.h>
#include <stdio.h>

unsigned int setbits(unsigned int x, int p, int n, unsigned int y);

int main(int argc, char** argv) {
	unsigned long int x; 
	int p; 
	int n; 
	unsigned long int y;

	if (argc < 5) {
		printf("x with n bits that begin at position p set to the rightmost n bits of y, leaving other bits unchanged\n");
		printf("Usage: %s x p y n\n", argv[0]);
		return -1;
	}

	// TODO: error check? Other bases?
	x = strtoul(argv[1], NULL, 2);
	p = atoi(argv[2]);
	n = atoi(argv[3]);
	y = strtoul(argv[4], NULL, 2);

	// TODO: print it in binary?
	printf("%u\n", setbits(x, p, n, y));

	return 0;
}

unsigned int setbits(unsigned int x, int p, int n, unsigned int y) {

	// Grab bits of x
	x = x & ( (~0 << (p+1)) | ~(~0 << (p+1-n)) );
	//printf("x = %u\n", x);

	// Grab bits of y
	y = y & ( ~(~0 << n) << (p+1-n) );
	//printf("y = %u\n", y);

	// OR the two
	return x | y;
}