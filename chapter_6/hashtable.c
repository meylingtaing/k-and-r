#include <stdlib.h>
#include <string.h>

#define HASHSIZE 101

struct nlist {
	struct nlist *next;
	char *name;
	char *defn;
};

static struct nlist *hashtab[HASHSIZE]; // ptr table

/* hash: form hash value for string s */
unsigned hash(char *s)
{
	unsigned hashval;

	for (hashval = 0; *s != '\0'; s++)
		hashval = *s + 31 * hashval;

	return hashval % HASHSIZE;
}

/* lookup: look for s in hashtab */
struct nlist *lookup(char *s)
{
	struct nlist *np;

	for (np = hashtab[hash(s)]; np != NULL; np = np->next)
		if (strcmp(s, np->name) == 0)
			return np;

	return NULL;
}

char *mystrdup(char *);

/* install: put (name, defn) in hashtab */
struct nlist *install(char *name, char *defn)
{
	struct nlist *np;
	unsigned hashval;

	// Not found
	if ((np=lookup(name)) == NULL) {
		np = (struct nlist *) malloc(sizeof(*np));
		
		// In case malloc-ing fails
		if (np == NULL || (np->name = mystrdup(name)) == NULL)
			return NULL;

		hashval = hash(name);
		np->next = hashtab[hashval];
		hashtab[hashval] = np;
	}

	// Already there
	else 
		free(np->defn);

	if ((np->defn = strdup(defn)) == NULL)
		return NULL;

	return np;
}

/* undef: remove a name and definition from the table */
void undef(char *name)
{
	unsigned int hashval = hash(name);
	struct nlist *curr = hashtab[hashval];
	struct nlist *prev = NULL;

	// Name doesn't exist
	if (curr == NULL)
		return;

	while (curr != NULL && strcmp(name, curr->name) != 0)
		prev = curr;

	if (prev == NULL)
		hashtab[hashval] = NULL;
	else
		prev->next = curr->next;
	free(curr->name);
	free(curr->defn);
	free(curr);
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