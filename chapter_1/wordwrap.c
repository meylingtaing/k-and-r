/* 'Fold' lines after a certain length. The lines might go over
	80 characters if it ends in a space or a tab */

#include <stdio.h>

#define WRAP 29
#define TABSTOP 4

int main() {
	int c;
	char wordbuf[WRAP+1];
	int wordlen = 0;
	int col = 0;

	// Print word by word
	while ( (c=getchar()) != EOF ) {
		
		// See if we just finished buffering a word
		if (c == '\n' || c == '\t' || c == ' ') {
			if (wordlen > 0) {
				wordbuf[wordlen] = 0;

				if ( (col + wordlen) >= WRAP ) {
					putchar('\n');
					col = 0;
				}

				printf("%s", wordbuf);
				col += wordlen;
				wordlen = 0;
			}

			putchar(c);

			if (c == '\t')
				col += TABSTOP;
			else if (c == ' ')
				col++;
			else
				col = 0;
		}

		else {
			if (wordlen >= WRAP) {
				// Print out the whole line
				wordbuf[wordlen] = 0;
				printf("%s-\n", wordbuf);
				wordlen = 0;
				col = 0;
			}

			wordbuf[wordlen] = c;
			wordlen++;
		}
	}

	// one more print
	wordbuf[wordlen] = 0;
	printf("%s\n", wordbuf);

	return 0;
}
