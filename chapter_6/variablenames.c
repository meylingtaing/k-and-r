/* Write a program that reads a C program and prints in alphabetical order each
   group of variables names that are identical in the first n characters, but
   different somewhere thereafter. */

// Ignoring typedefs for now
// Also ignoring structs

/* This program is crazy messy and not even that correct. But I'm tired of 
   working on it. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LETTERS 6
#define LEN 100
#define NUM_TYPES sizeof var_types / sizeof (char *)

struct tnode {
	char *word;
	struct tnode *left;
	struct tnode *right;
};

char *var_types[] = {"int", "char", "double", "float", "void",
									"long", "short"};
int letters;

int gettoken(char *word, int lim);
int getch(void);
int ungetch(int c);
int exists(char *word, char *arr[], int arrsize);
struct tnode *addword(struct tnode *root, char *word);
void treeprint(struct tnode *root);

enum {OTHER, LINE_COMMENT, BLOCK_COMMENT, STRING, CHARACTER, 
	DECL, DEFINE};

int main(int argc, char *argv[])
{
	char token[LEN];
	char temptoken[LEN];
	letters = LETTERS;
	struct tnode *root = NULL;
	int state = OTHER;
	int prevstate = OTHER;
	int c;

	if (argc > 1)
		letters = atoi(argv[1]);

	while ( (c=gettoken(token, LEN)) != EOF) {
		switch (state) {
			case OTHER:
				if (strcmp(token, "/*") == 0)
					state = BLOCK_COMMENT;
				else if (strcmp(token, "//") == 0)
					state = LINE_COMMENT;
				else if (strcmp(token, "\"") == 0)
					state = STRING;
				else if (strcmp(token, "\'") == 0)
					state = CHARACTER;
				else if (exists(token, var_types, NUM_TYPES))
					state = DECL;
				else if (token[0] == '#')
					state = DEFINE;

				prevstate = OTHER;
				break;
			case LINE_COMMENT:
				while (getch() != '\n');
				state = prevstate;
				break;
			case BLOCK_COMMENT:
				if (strcmp(token, "*/") == 0)
					state = prevstate;
				break;
			case STRING:
				if (strcmp(token, "\"") == 0)
					state = prevstate;
				break;
			case CHARACTER:
				if (strcmp(token, "\'") == 0)
					state = prevstate;
				break;
			case DEFINE:
				while (getch() != '\n');
				state = prevstate;
				break;
			case DECL:
				if (strcmp(token, "/*") == 0)
					state = BLOCK_COMMENT;
				else if (strcmp(token, "//") == 0)
					state = LINE_COMMENT;
				else if (isalpha(token[0]) && 
						 !exists(token, var_types, NUM_TYPES)) {
					if (gettoken(temptoken, LEN) == '(') {
						state = OTHER;
						break;
					}
					root = addword(root, token);

					while (strcmp(temptoken, ",") != 0 && 
						   strcmp(temptoken, ";") != 0) {
						if (strcmp(token, "/*") == 0)
							state = BLOCK_COMMENT;
						else if (strcmp(token, "//") == 0)
							state = LINE_COMMENT;

						gettoken(temptoken, LEN);
					}

					if (c == ';')
						state = OTHER;
				}
				prevstate = DECL;

				//printf("Next state: %d\n", state);
				break;
		}
	}

	treeprint(root);
	return 0;
}

/* exists: determine if word is in arr */
int exists(char *word, char *arr[], int arrsize)
{
	int i;
	for (i = 0; i < arrsize; i++)
		if (strcmp(word, arr[i]) == 0)
			return 1;

	return 0;
}

struct tnode *talloc(void);
char *mystrdup(char *, int);

/* addtree: add a node with w, at or below p */
struct tnode *addword(struct tnode *p, char *w)
{
	int cond;

	// Tree doesn't exist yet
	if (p == NULL) {
		p = talloc();
		p->word = mystrdup(w, letters);
		p->left = p->right = NULL;
		printf("Adding %s to tree\n", p->word);
	}
	// Word exists
	else if ((cond=strncmp(w, p->word, letters)) == 0) {
		//printf("%s already exists\n", w);
		return p;
	}
	// Word is less than current word
	else if (cond < 0)
		p->left = addword(p->left, w);
	else
		p->right = addword(p->right, w);

	return p;
}

/* treeprint: in-order print of tree */
void treeprint(struct tnode *p)
{
	if (p != NULL) {
		treeprint(p->left);
		printf("%s\n", p->word);
		treeprint(p->right);
	}
}

/* talloc: make a tnode */
struct tnode *talloc(void)
{
	return (struct tnode *) malloc(sizeof(struct tnode));
}

/* strdup: make a duplicate of s */
char *mystrdup(char *s, int letters)
{
	char *p;

	p = (char *) malloc(letters + 1);
	if (p != NULL)
		strncpy(p, s, letters);

	return p;
}
