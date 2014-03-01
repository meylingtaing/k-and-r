/* write squeeze(s1, s2) which deletes each character in s1 that matches any
   character in the string s2 */

#include <stdio.h>

void squeeze(char s1[], char s2[]);
int str_contains(char str[], char c);

int main (int argc, char** argv) {
	if (argc < 3) {
		printf("Usage: %s str_to_modify remove_these_chars\n", argv[0]);
		return -1;
	}

	squeeze(argv[1], argv[2]);
	printf("%s\n", argv[1]);

	return 0;
}

void squeeze(char s1[], char s2[]) {
	int i, j;

	for (i = j = 0; s1[i] != 0; i++) {
		if (!str_contains(s2, s1[i]))
			s1[j++] = s1[i];
	}
	s1[j] = 0;
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