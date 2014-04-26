#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100
#define NKEYS (int)(sizeof keytab / sizeof keytab[0])

struct key {
	char *word;
	int count;
} keytab[] = {
	{"auto", 0},
	{"break", 0}, 
	{"case", 0},
	{"char", 0},
	{"const", 0},
	{"continue", 0},
	{"default", 0},
	{"define", 0},
	{"double", 0},
	{"float", 0},
	{"for", 0},
	{"if", 0},
	{"include", 0}, 
	{"int", 0},
	{"struct", 0},
	{"typedef", 0},
	{"unsigned", 0},
	{"void", 0},
	{"volatile", 0},
	{"while", 0}
};

int getword(char *, int);
int binarysearch(char *, struct key *, int);

/* count c keywords */
int main()
{
	int n;
	char word[MAXWORD];

	while (getword(word, MAXWORD) != EOF)
		if (isalpha(word[0]) || word[0] == '_')
			if ((n=binarysearch(word, keytab, NKEYS)) >= 0)
				keytab[n].count++;

	for (n = 0; n < NKEYS; n++)
		printf("%4d %s\n", keytab[n].count, keytab[n].word);

	return 0;
}

/* binarysearch: find word in tab[0]...tab[n-1] */
int binarysearch(char *word, struct key tab[], int n)
{
	int cond;
	int low, high, mid;

	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low+high)/2;

		if ((cond=strcmp(word, tab[mid].word)) < 0)
			high = mid - 1;
		else if (cond > 0)
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}