/* Grep-like program */

#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000

int getline_stdin(char line[], int max);
int findstrindex(char source[], char searchfor[]);

char pattern[] = "ould";

int main() {
	char line[MAXLINE];
	int found = 0;

	while (getline_stdin(line, MAXLINE) > 0)
		if (findstrindex(line, pattern) >= 0) {
			printf("%s", line);
			found++;
		}

	return found;
}

/* getline: get line into s, return length */
int getline_stdin(char s[], int lim) {
	int c, i;

	i = 0;
	while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
		s[i++] = c;

	if (c == '\n')
		s[i++] = c;

	s[i] = 0;
	return i;
}

/* strindex: return index of t in s, -1 if none */
int findstrindex(char s[], char t[]) {
	int i, j, k;

	for (i = 0; s[i] != 0; i++) {
		for (j=i, k=0; t[k]!=0 && s[j]==t[k]; j++, k++);

		if (k > 0 && t[k] == 0) 
			return i;
	}
	return -1;
}