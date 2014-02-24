/* Removes trailing blanks and tabs from each line of input and deletes
new lines */

#include <stdio.h>

#define MAXLINE 1000

int main() {
	int c, last;
	char buffer[MAXLINE];
	int i = 0;
	last = '\n';

	while ((c=getchar()) != EOF) {
		if (c == '\n' || c == '\r') {
			i = 0;
			if (last != '\n') {
				printf("\n");
				last = '\n';
			}
			continue;
		}

		// If c is whitespace
		if (c == '\t' || c == ' ') {
			buffer[i++] = c;
		}

		else {
			if (i > 0) {
				buffer[i] = '\0';
				i = 0;
				printf("%s", buffer);
			}
			putchar(c);
			last = c;
		}
	}

	return 0;
}