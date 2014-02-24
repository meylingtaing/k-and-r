/* Prints input one word per line */

#include <stdio.h>

#define IN 	1	// Inside a word
#define OUT	0	// Outside a word

int main() {
	int state, c;
	int put_last;

	state = OUT;

	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t' || c == '\r') {
 			state = OUT;
 			if (put_last != '\n') {
 				putchar('\n');
 				put_last = '\n';
 			}
		}
		else
			state = IN;

 		if (state == IN) {
 			putchar(c);
 			put_last = c;
 		}
	}

	return 0;
}