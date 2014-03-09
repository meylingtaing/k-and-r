/* getch and ungetch functions which hold a buffer */

#include <stdio.h>

#define BUFSIZE 100

char buf[BUFSIZE];	// Buffer for ungetch
int bufp;			// Buffer pointer -- next free position in buf

// getch: get a (possibly pushed back) character
int getch(void) {
	return (bufp > 0) ? buf[--bufp] : getchar();
}

// ungetch: push character back on input
void ungetch(int c) {
	if (bufp >= BUFSIZE)
		printf("ungetch Error: too many characters\n");
	else
		buf[bufp++] = c;
}