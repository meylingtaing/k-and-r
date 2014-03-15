/* Print an integer as a string */

#include <stdio.h>
#define BUF 100

int itoa(int n, char str[]);

int main() {
	int numbers[] = {40, 892, 4352, 352, -999, 1003};
	int i;
	char str[BUF];

	for (i = 0; i < 6; i++) { 
		itoa(numbers[i], str);
		printf("%s\n", str);
	}
}

int itoa(int n, char str[])
{
	int i = 0;
	int j = 0;
	int end_index;

	if (n < 0) {
		str[i++] = ('-');
		n = -n;
	}

	if (n / 10)
		j = itoa(n / 10, str + i);

	end_index = i+j;
	str[end_index++] = (n % 10 + '0');
	str[end_index] = 0;

	return end_index;
}