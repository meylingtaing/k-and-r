/* Rewrite readlines to store lines in an array stored by main */

#include <string.h>
#include <stdio.h>

#define MAXLEN 1000

int getline_stdin(char *, int);
char *alloc(int);

/* readlines: read input lines */
int readlines(char lineptr[][MAXLEN], int maxlines)
{
	int len, nlines;

	nlines = 0;
	while ( (len = getline_stdin(lineptr[nlines], MAXLEN)) > 0) {
		if (nlines >= maxlines)
			return -1;
		else {
			lineptr[nlines][len - 1] = 0; // delete newline
			nlines++;
		}
	}
	return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
	int i;

	for (i = 0; i < nlines; i++)
		printf("%s\n", lineptr[i]);
}