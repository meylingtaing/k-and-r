/* Write the function any(s1, s2) which returns the first location in s1 where
   any character in s2 exists */

#include <stdio.h>

int any(char s1[], char s2[]);
int str_contains(char str[], char c);

int main(int argc, char** argv) {
	int index;

	if (argc < 3) {
		printf("Usage: %s string_to_search chars_to_look_for\n", argv[0]);
		return -1;
	}

	index = any(argv[1], argv[2]);
	if (index >= 0)
		printf("The first occurence is at index %d\n", index);
	else
		printf("Those characters do not appear in the string %s", argv[1]);

	return 0;
}

int any(char s1[], char s2[]) {
	int i = 0;
	while (s1[i] != 0) {
		if (str_contains(s2, s1[i]))
			return i;
		i++;
	}

	// Return -1 if it's not found
	return -1;
}

int str_contains(char str[], char c) {
	int i = 0;

	while (str[i] != 0) {
		if (str[i] == c)
			return 1;
		i++;
	}
	return 0;
}