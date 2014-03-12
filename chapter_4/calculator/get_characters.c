/* getch and ungetch functions which hold a buffer */

/* Write function ungets(s) that will push back an entire string onto the 
   input */

/* Ex 4-8 says suppose there will never be more than one character of push
   back. Well, if that's the case, then buf just needs to be a char, not a 
   char array. Which completely invalidates 4-7, so I'm not going to bother
   doing this one. */

#include <stdio.h>
#include <string.h>

#define BUFSIZE 100

char buf[BUFSIZE];	// Buffer for ungetch
int bufp;			// Buffer pointer -- next free position in buf

// getch: get a (possibly pushed back) character
int getch(void) {
	return (bufp > 0) ? buf[--bufp] : getchar();
}

// ungetch: push character back on input
int ungetch(int c) {
	if (bufp >= BUFSIZE) {
		printf("ungetch Error: too many characters\n");
		return 0;
	}
	else {
		buf[bufp++] = c;
		return 1;
	}
}

// ungets: push back a string
void ungets(char s[]) {
	// String must be pushed backwards
	int i = strlen(s) - 1;
	for (; i >= 0; i--) {
		if (ungetch(s[i]) == 0)
			break;
	}
}