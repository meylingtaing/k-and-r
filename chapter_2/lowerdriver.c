/* Write function lower with ternary operator */

#include <stdio.h>

int lower(int c);

int main(int argc, char** argv) {
	int i = 0;

	if (argc < 2) {
		printf("Usage: %s string_to_lower\n", argv[0]);
		return -1;
	}

	while (argv[1][i] != 0) {
		putchar(lower(argv[1][i]));
		i++;
	}
	putchar('\n');

	return 0;
}

int lower(int c) {
	return (c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : c;
}