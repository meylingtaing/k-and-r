/* Write a program that prints the distinct words in its input sorted into 
   order of frequency of occurrence. Precede each word by its count */

// I can't tell if this program is slow or my connection is bad...

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100

struct tnode {
	char *word;				// points to the text
	int count;				// number of occurrences
	struct tnode *left;		// left child
	struct tnode *right;	// right child
};

struct tnode *addtree(struct tnode *, char *);
struct tnode *addtreesorted(struct tnode *, struct tnode *);
void treeprint(struct tnode *);
int getword(char *, int);
struct tnode *sorttree(struct tnode *, struct tnode *);

/* word frequency count */
int main()
{
	struct tnode *root = NULL;
	struct tnode *rootsorted = NULL;
	char word[MAXWORD];

	while (getword(word, MAXWORD) != EOF)
		if (isalpha(word[0]))
			root = addtree(root, word);

	rootsorted = sorttree(root, rootsorted);
	treeprint(rootsorted);
	return 0;
}

struct tnode *talloc(void);
char *mystrdup(char *);

/* addtree: add a node with w, at or below p */
struct tnode *addtree(struct tnode *p, char *w)
{
	int cond;

	// Tree doesn't exist yet
	if (p == NULL) {
		p = talloc();
		p->word = mystrdup(w);
		p->count = 1;
		p->left = p->right = NULL;
	}
	// At the right word, increment frequency
	else if ((cond=strcmp(w, p->word)) == 0)
		p->count++;
	// Word is less than current word
	else if (cond < 0)
		p->left = addtree(p->left, w);
	else
		p->right = addtree(p->right, w);

	return p;
}

struct tnode *addtreesorted(struct tnode *root, struct tnode *newroot)
{
	// Add the root node
	if (newroot == NULL) { 
		newroot = root;
		newroot->left = NULL;
		newroot->right = NULL;
	}
	else if (root->count > newroot->count) 
		newroot->left = addtreesorted(root, newroot->left);
	else
		newroot->right = addtreesorted(root, newroot->right);

	return newroot;
}

struct tnode *sorttree(struct tnode *root, struct tnode *newroot)
{
	if (root == NULL)
		return NULL;

	if (root->left != NULL)
		newroot = sorttree(root->left, newroot);

	if (root->right != NULL)
		newroot = sorttree(root->right, newroot);

	newroot = addtreesorted(root, newroot);

	return newroot;
}

/* treeprint: in-order print of tree */
void treeprint(struct tnode *p)
{
	if (p != NULL) {
		treeprint(p->left);
		printf("%4d %s\n", p->count, p->word);
		treeprint(p->right);
	}
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