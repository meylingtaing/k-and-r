#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define NUM_TYPES 6

int getch(void);
int ungetch(int c);

/* gettoken: gets the next token from a C program */
int gettoken(char *token, int limit)
{
	int c;
	char *t = token;

	// Get past whitespace
	while ( isspace(c=getch()) );
	*t++ = c;

	if (c == EOF)
		return EOF;

	// If it's a variable name or keyword
	if (isalpha(c) || c == '_') {
		// Rest of letters
		while (--limit > 0 && ((c=getch()) == '_' || isalnum(c)) )
			*t++ = c;

		// Undo the last character, which was non-alnum
		ungetch(c);
	}

	// Slash means it might be a comment
	else if (c == '/') {
		if ((c=getch()) == '/' || c == '*')
			*t++ = c;
		else
			ungetch(c);
	}

	// Also checking for end of block comment
	else if (c == '*') {
		if ((c=getch()) == '/')
			*t++ = c;
		else
			ungetch(c);
	}

	// Pretty sure back slashes always have to escape something
	else if (c == '\\')
		*t++ = getch();

	// Grab stuff after #
	else if (c == '#') {
		char temptoken[20];
		gettoken(temptoken, 20);
		strcat(token, temptoken);
	}

	*t = '\0';
	return token[0];
}