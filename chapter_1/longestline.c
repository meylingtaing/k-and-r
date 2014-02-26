/* From a textfile, get the longest line */

#include <stdio.h>
#define MAXLINE 80

int getline_stdin(char s[], int lim);
void copy(char to[], char from[]);

int main() {
	int len; 				// Current line length
	int max;				// Max line length so far
	char line[MAXLINE];		// Current input line
	char longest[MAXLINE]; 	// Longest input line so far

	max = 0;
	while ((len = getline_stdin(line, MAXLINE)) > 0)
		if (len > max) {
			max = len;
			copy(longest, line);
		}

	if (max > 0)
		printf("%d characters: %s", max, longest);

	return 0;
}

/* getline: read a line into s, return length */
int getline_stdin(char s[], int lim) {
	int c, i;
	int len;

/*
	for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; i++)
		s[i] = c;
*/
	// Ex 2-2
	for (i = 0; i < lim-1; i++) {
		c = getchar();
		if (c == EOF)
			break;
		if (c == '\n')
			break;
		s[i] = c;
	}

	if (c == '\n') {
		s[i] = c;
		i++;
	}
	len = i;

	while (c != EOF && c != '\n') {
		c = getchar();
		len++;
	}

	s[i] = '\0';

	return len;
}

/* copy: copy 'from' into 'to', assuming to is big enough */
void copy(char to[], char from[]) {
	int i = 0;

	while ((to[i] = from[i]) != '\0')
		i++;
}