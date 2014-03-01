/* Write a function htoi, which converts a hex string to an integer */
#include <stdio.h>

#define HEXBASE 16

int htoi(char* str);

int main(int argc, char** argv) {

	if (argc < 2) {
		printf("Usage: %s hexnumber\n", argv[0]);
		return -1;
	}

	printf("%s in decimal is %d.\n", argv[1], htoi(argv[1]));

	return 0;

}

/* Assuming valid input */
int htoi(char* str) {
	int i = 0;
	int value = 0;

	// Check for optional 0x
	if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X') )
		i = 2;

	// Keep reading until end of string
	while (str[i] != 0) {
		int digit;

		if (str[i] >= '0' && str[i] <= '9')
			digit = str[i] - '0';
		else if (str[i] >= 'A' && str[i] <= 'F')
			digit = str[i] - 'A' + 10;
		else if (str[i] >= 'a' && str[i] <= 'f')
			digit = str[i] - 'a' + 10;

		value = value * HEXBASE + digit;
		i++;
	}

	return value;
}