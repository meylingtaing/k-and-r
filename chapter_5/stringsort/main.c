#include <stdio.h>
#include <string.h>

#define MAXLINES 5000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines, int reverse);

void my_qsort(void *lineptr[], int left, int right, 
	       int (*comp)(void *, void *));
int numcmp(char *, char *);
int ignorecasecmp(char *, char *);

int main(int argc, char *argv[])
{
	int nlines;			// number of lines to be read
	int numeric = 0;	// 1 if numeric sort
	int reverse = 0;
	int case_sensitive = 1;

	while (--argc > 0) {
		int i = 0;
		int c;
		if (argv[argc][i] == '-') {
			while ((c = argv[argc][++i]) != 0)
				if (c == 'r')
					reverse = 1;
				else if (c == 'n')
					numeric = 1;
				else if (c == 'f')
					case_sensitive = 0;
		}
	}

	//printf("Reverse: %d, Numeric: %d\n", reverse, numeric);

	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {

		int (*comp)(void *, void *) = strcmp;
		if (numeric)
			comp = numcmp;
		else if (!case_sensitive)
			comp = ignorecasecmp;

		my_qsort((void **) lineptr, 0, nlines-1, comp);
		writelines(lineptr, nlines, reverse);
		return 0;
	}
	else {
		printf("Input too big to sort\n");
		return 1;
	}
}