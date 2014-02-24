/* Convert spaces to tabs */

#include <stdio.h>
#define TABSTOP 4

int main() {
	int c, i;
	int spaces_needed = 0;
	int cols = 0;
	while ((c = getchar()) != EOF) {
		cols++;

		if (c == ' ') {
			spaces_needed++;

			if ( (cols % TABSTOP) == 0) {
				putchar('\t');
				spaces_needed = 0;
			}
		}

		else if (c == '\t') {
			putchar('\t');
			spaces_needed = 0;

			while (cols % TABSTOP != 0)
				cols++;
		}

		else {
			for (i = 0; i < spaces_needed; i++)
				putchar(' ');
			
			putchar(c);
			spaces_needed = 0;

			if (c == '\n')
				cols = 0;
		}
	}

	return 0;
}