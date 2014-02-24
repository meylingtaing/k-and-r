/* Print all lines longer than 80 characters */

#include <stdio.h>
#define MAXLINE 1000

int getline_stdin(char s[], int lim);

int main () {
	char line[MAXLINE];
	int len;

	while ((len = getline_stdin(line, MAXLINE)) > 0) {
		if (len >= 80)
			printf("%s", line);
	}

	return 0;
}

int getline_stdin(char s[], int lim) {
	int c;
	int i = 0;

	int len;

	while (i < lim-2) {
		c = getchar();

		if (c == '\n' || c == EOF)
			break;

		s[i] = c;
		i++;
	}

	len = i;

	s[i] = '\n';
	s[++i] = 0;

	return len;
}