/* Write a program that prints a list of all words in a document, and, for each
   word, a list of the line numbers on which it occurs. The numbers will be
   displayed in reverse order...because that's easier for me. */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "llist.h"
#define MAXLINES 1000
#define MAXWORDLEN 1000
#define WORDSKIPPED sizeof skip / sizeof (char *)

struct tnode {
	char *word;				// points to the text
	llist *lines;			// number of occurrences
	struct tnode *left;		// left child
	struct tnode *right;	// right child
};

char *skip[] = {"the", "you", "a", "i", "to", "that", "of", "on", "in", "is",
				"and"};

struct tnode *addtree(struct tnode *, char *, int *);
void treeprint(struct tnode *);
int getword(char *, int);
void numprint(void *);
int exists(char *word, char *arr[], int arrsize);

int main()
{
	int lines[MAXLINES];
	char word[MAXWORDLEN];
	struct tnode *root = NULL;
	int i;

	for (i = 0; i < MAXLINES; i++)
		lines[i] = i+1;

	i = 0;

	while (getword(word, MAXWORDLEN) != EOF) {
		if (isalpha(word[0]) && !exists(word, skip, WORDSKIPPED))
			root = addtree(root, word, &lines[i]);
		else if (word[0] == '\n')
			i++;

		//printf("Main Loop, i = %d, word = %s\n", i, word);
	}

	treeprint(root);

	return 0;
}

/* numprint: prints a number */
void numprint(void *num)
{
    int *pnum = (int *)num;
    if (num == NULL) 
        return;
    
    printf("%d", *pnum);
}

struct tnode *talloc(void);
char *mystrdup(char *);

/* addtree: add a node with w, at or below p */
struct tnode *addtree(struct tnode *p, char *w, int *line)
{
	int cond;

	// Tree doesn't exist yet
	if (p == NULL) {
		p = talloc();
		p->word = mystrdup(w);
		p->lines = llist_create(line);
		p->left = p->right = NULL;
	}
	// At the right word, increment frequency
	else if ((cond=strcmp(w, p->word)) == 0)
		llist_push(p->lines, line);
	// Word is less than current word
	else if (cond < 0)
		p->left = addtree(p->left, w, line);
	else
		p->right = addtree(p->right, w, line);

	return p;
}

/* talloc: make a tnode */
struct tnode *talloc(void)
{
	return (struct tnode *) malloc(sizeof(struct tnode));
}

/* strdup: make a duplicate of s */
char *mystrdup(char *s)
{
	char *p;

	p = (char *) malloc(strlen(s) + 1);
	if (p != NULL)
		strcpy(p, s);

	return p;
}

/* treeprint: in-order print of tree */
void treeprint(struct tnode *p)
{
	if (p != NULL) {
		treeprint(p->left);
		printf("%s: ", p->word);
		llist_print(p->lines, numprint);
		treeprint(p->right);
	}
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