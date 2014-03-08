/* Write function strrindex(s, t) which returns position of rightmost
   rightmost occurence of t in s */

#include <stdio.h>
#include <string.h>

int strrindex(char s[], char t[]);

int main(int argc, char** argv) {
	if (argc < 3) {
		printf("Usage: %s string patterntofind\n", argv[0]);
		return -1;
	}

	printf("%d\n", strrindex(argv[1], argv[2]));
	return 0;
}

int strrindex(char s[], char t[]) {
	int s_len = strlen(s);
	int t_len = strlen(t);
	int i;

	// Iterating backwards
	for (i = s_len-1; i >= t_len-1; i--) {
		int j = i;
		int k = t_len-1;
		while (k >= 0 && s[j--] == t[k--]);

		if (k < 0)
			return j+1;
	}

	return -1;
}