/* Pointer version of strcat */

#include <stdio.h>
#define BUF 1000

void my_strcat(char *s, char *t);

int main() 
{
	char str1[BUF] = "Hello ";
	char str2[] = "World!";

	my_strcat(str1, str2);

	printf("%s\n", str1);

	return 0;
}

void my_strcat(char *s, char *t) 
{
	// Get to end of s
	while (*s != 0)
		s++;

	// Add t
	while (*s++ = *t++);
}