#include <stdio.h>
#include <string.h>

#define MAXLINES 5000
#define MAXLEN 1000

char *lineptr[MAXLINES];
char linearr[MAXLINES][MAXLEN];

int readlines(char lineptr[][MAXLEN], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

/* sort input lines */
int main() 
{
	int nlines;

	if ( (nlines=readlines(linearr, MAXLINES)) >= 0) {
		int i;
		for (i = 0; i < nlines; i++)
			lineptr[i] = linearr[i];

		qsort(lineptr, 0, nlines-1);
		writelines(lineptr, nlines);
		return 0;
	}
	else {
		printf("Error: input too big to sort\n");
		return 1;
	}
}