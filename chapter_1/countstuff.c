/* count digits, white space, others */

#include <stdio.h>

int main() {

	int c, num_white, num_other;
	int num_dig[10];
	int i;

	num_white = num_other = 0;
	for (i = 0; i < 10; i++)
		num_dig[i] = 0;

	while ((c = getchar()) != EOF)
		if (c >= '0' && c <= '9')
			num_dig[c-'0']++;

		else if (c == ' ' || c == '\n' || c == '\t')
			num_white++;

		else
			num_other++;
	
	printf("digits =");
	for (i = 0; i < 10; i++)
		printf(" %d", num_dig[i]);

	printf(", white space = %d, other = %d\n", num_white, num_other);

	return 0;
}