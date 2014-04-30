/* This is just a driver progrm for the hash table */
#include <stdio.h>

struct nlist {
	struct nlist *next;
	char *name;
	char *defn;
};

struct nlist *lookup(char *s);
struct nlist *install(char *name, char *defn);
void undef(char *name);

int main()
{
	struct nlist *curr = NULL;

	// Give passwords to all of them
	install("meyling", "chickens");
	install("ching", "cows");
	install("robert", "poop");
	install("meyling", "chickeneggs");

	// Look them up
	curr = lookup("ching");
	printf("ching's password: %s\n", curr->defn);
	curr = lookup("meyling");
	printf("meyling's password: %s\n", curr->defn);
	curr = lookup("robert");
	printf("robert's password: %s\n", curr->defn);

	// Remove some stuff
	undef("meyling");
	curr = lookup("meyling");
	if (curr == NULL)
		printf("Successfully removed meyling\n");

	return 0;
}