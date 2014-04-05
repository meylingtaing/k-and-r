#include <stdio.h>
#include <string.h>

#define MAXLINES 5000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines, int reverse);

void my_qsort(void *lineptr[], int left, int right, 
	       int (*comp)(void *, void *));
int numcmp(char *, char *);

int main(int argc, char *argv[])
{
	int nlines;			// number of lines to be read
	int numeric = 0;	// 1 if numeric sort
	int reverse = 0;

	while (--argc > 0) {
		int i = 0;
		int c;
		if (argv[argc][i] == '-') {
			while ((c = argv[argc][++i]) != 0)
				if (c == 'r')
					reverse = 1;
				else if (c == 'n')
					numeric = 1;
		}
	}

	printf("Reverse: %d, Numeric: %d\n", reverse, numeric);

	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		my_qsort((void **) lineptr, 0, nlines-1, 
			  (int (*)(void *, void *))(numeric ? numcmp : strcmp));
		writelines(lineptr, nlines, reverse);
		return 0;
	}
	else {
		printf("Input too big to sort\n");
		return 1;
	}
}