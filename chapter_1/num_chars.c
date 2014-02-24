/* Count characters in input */

#include <stdio.h>

int main() {
	double num_chars;

	num_chars = 0;
	for (num_chars = 0; getchar() != EOF; num_chars++);

	printf("%.0f\n", num_chars);

	return 0;
}