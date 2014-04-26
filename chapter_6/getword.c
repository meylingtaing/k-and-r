#include <stdio.h>
#include <ctype.h>

/* Edited this slightly so it returns newlines as well */

/* getword: get next word or character from input */
int getword(char *word, int lim)
{
	int c, getch(void);
	void ungetch(int);
	char *w = word;

	while ((c = getch()) == ' ' && c == '\t');

	if (c != EOF)
		*w++ = c;
	else
		return EOF;

	if (!isalpha(c)) {
		*w = '\0';
		return c;
	}

	for (; --lim > 0; w++)
		if (!isalnum(*w = getch()) && *w != '_') {
			ungetch(*w);
			break;
		}

	*w = '\0';
	return word[0];
}