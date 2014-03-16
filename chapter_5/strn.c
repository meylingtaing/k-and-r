/* Write functions strncpy, strncmp, strncat */

#include <stdio.h>
#define BUF 1000

void my_strncpy(char *s, char *t, int n);
void my_strncat(char *s, char *t, int n);
int my_strncmp(char *s, char *t, int n);

int main() 
{
	char str0[BUF];
	char str1[BUF] = "Hello ";
	char str2[] = "Worlddddddd";

	char str4[] = "Applesauce";
	char str5[] = "Applespoos";

	my_strncpy(str0, str2, 5);
	str0[5] = 0;

	printf("%s\n", str0);

	my_strncat(str1, str2, 5);
	printf("%s\n", str1);

	printf("%s %s\n", str4, str5);
	printf("%d, %d\n", 4, my_strncmp(str4, str5, 4));
	printf("%d, %d\n", 5, my_strncmp(str4, str5, 5));
	printf("%d, %d\n", 6, my_strncmp(str4, str5, 6));
	printf("%d, %d\n", 7, my_strncmp(str4, str5, 7));

	return 0;
}

void my_strncpy(char *s, char *t, int n)
{
	while ( (*s++ = *t++) && (--n > 0) );

	while (--n >= 0)
		*s++ = 0;
}

void my_strncat(char *s, char *t, int n) 
{
	// Get to end of s
	while (*s != 0)
		s++;

	// Add t
	while ( (*s++ = *t++) && (--n > 0) );
	*s = 0;
}

int my_strncmp(char *s, char *t, int n)
{
	for (; *s == *t && --n > 0; s++, t++)
		if (*s == 0)
			return 0;

	return *s - *t;
}