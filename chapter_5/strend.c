/* Write function strend(s,t) which returns 1 if t is at end of s */

#include <stdio.h>
#include <string.h>

int strend(char *s, char *t);

int main() 
{
	char *str1 = "Hello";
	char *str2 = "Pineapple";

	printf("%s, %s, %d\n", str1, "lo", strend(str1, "lo"));
	printf("%s, %s, %d\n", str1, "ello", strend(str1, "ello"));
	printf("%s, %s, %d\n", str1, "poo", strend(str1, "poo"));
	printf("%s, %s, %d\n", str1, "", strend(str1, ""));
	printf("%s, %s, %d\n", str2, "apple", strend(str2, "apple"));
	printf("%s, %s, %d\n", str2, "e", strend(str2, "e"));
	printf("%s, %s, %d\n", str2, "APPLE", strend(str2, "APPLE"));

	return 0;
}

int strend(char *s, char *t) 
{
	int i = strlen(s) - 1;		// Index for s
	int j = strlen(t) - 1;		// Index for t

	// Make sure s is at least as long as t
	if (j > i)
		return 0;

	s = s+i;
	t = t+j;
	for (; j >= 0; s--, t--, j--) {
		if (*s != *t)
			return 0;
	}

	return 1;
}