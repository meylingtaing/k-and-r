/* getch and ungetch functions which hold a buffer */

/* Write function ungets(s) that will push back an entire string onto the 
   input */

/* Suppose there will never be more than one character of pushback. Modify
   getch and ungetch accordingly */

#include <stdio.h>
#include <string.h>

#define BUFSIZE 100

char buf;	// Buffer for ungetch
int filled = 0;

// getch: get a (possibly pushed back) character
int getch(void) {
	if (filled) {
		filled = 0;
		return buf;
	}
	else
		return getchar();
}

// ungetch: push character back on input
int ungetch(int c) {
	if (filled) {
		printf("ungetch Error: buffer is already filled\n");
		return 0;
	}
	else {
		buf = c;
		filled = 1;
		return 1;
	}
}

// ungets: push back a string
// No point in having this if we can only have one character in buffer
/*
void ungets(char s[]) {
	// String must be pushed backwards
	int i = strlen(s) - 1;
	for (; i >= 0; i--) {
		if (ungetch(s[i]) == 0)
			break;
	}
}
//*/