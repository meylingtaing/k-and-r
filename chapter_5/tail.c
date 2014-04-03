#include <stdio.h>
#include <stdlib.h>

#define LINES 	10
#define LINELEN	500

char *alloc(int n);
int getline_stdin(char s[], int lim);

int main(int argc, char **argv)
{
	int lines = LINES;
	char *buffer;
	int curr_line = 0;
	int i;

	if (argc > 1 && argv[1][0] == '-') {
		lines = atoi(argv[1]+1);

		if (lines <= 0) {
			printf("Error: %s is not a valid number\n", argv[1]+1);
			return -1;
		}
	}

	// Need to store lines number of lines
	buffer = alloc(lines * LINELEN);

	while (getline_stdin((buffer + curr_line*LINELEN), LINELEN))
	{
		curr_line = (curr_line + 1) % lines;
	}

	// Print the lines
	for (i = 0; i < lines; i++) {
		printf("%s",buffer+curr_line*LINELEN);
		curr_line = (curr_line + 1) % lines;
	}

	return 0;
}