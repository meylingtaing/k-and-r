/* count whitespace */

#include <stdio.h>

int main() {
	int num_spaces = 0, num_newlines = 0, num_tabs = 0;
	int c;		// Current character

	while ((c = getchar()) != EOF) {
		if (c == ' ')
			num_spaces++;
		else if (c == '\t')
			num_tabs++;
		else if (c == '\n')
			num_newlines++;
	}

	printf("Number of spaces: %d\n", num_spaces);
	printf("Number of tabs: %d\n", num_tabs);
	printf("Number of new lines: %d\n", num_newlines);

	return 0;
}