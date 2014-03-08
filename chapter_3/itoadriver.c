/* Modify itoa example in book to correctly deal with largest negative number
   It doesn't work because the largest negative number cannot be represented
   positively. The largest positive number is one smaller in magnitude. */

#include <limits.h>
#include <stdio.h>

#define BUFF 100

void itoa(int n, char s[]);
void reverse(char* str);

int main() {
	char str[BUFF];

	itoa(INT_MIN, str);
	printf("Minimum: %s\n", str);
	itoa(INT_MAX, str);
	printf("Maximum: %s\n", str);

	return 0;
}

void itoa(int n, char s[]) {
	int i, sign;
	int largest_neg = 0;

	if (n == INT_MIN) {
		n++;
		largest_neg = 1;
	}

	if ( (sign=n) < 0)
		n = -n;

	i = 0;
	do {
		s[i++] = n % 10 + '0';
	} while ( (n/=10) > 0);

	if (sign < 0)
		s[i++] = '-';

	s[i] = '\0';

	// So there's no way that the LSD is a 9, so this hack should work
	if (largest_neg)
		s[0] += 1;

	reverse(s);
}

void reverse(char* str) {
    int start = 0;
    int end;
    int len;

    len = 0;
    while (str[len] != 0)
        len++;

    end = len - 1;

    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        start++;
        end--;
    }
}