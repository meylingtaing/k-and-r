/* Copy input to output, replacing each string of one or more blanks
   by a single blank */

#include <stdio.h>

int main() {
	int curr, prev;

	// First character
	prev = getchar();
	putchar(prev);

	while ((curr = getchar()) != EOF) {
		if (curr == ' ' && prev == ' ')
			continue;

		putchar(curr);
		prev = curr;
	}

	return 0;
}