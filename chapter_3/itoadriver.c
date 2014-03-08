/* Modify itoa example in book to correctly deal with largest negative number
   It doesn't work because the largest negative number cannot be represented
   positively. The largest positive number is one smaller in magnitude. */

/* Write function itob(n, s, b) to show the string representation with any
   base */

#include <limits.h>
#include <stdio.h>

#define BUFF 100

void itoa(int n, char s[]);
void reverse(char* str);
void itob(int n, char s[], int b);

int main() {
	char str[BUFF];

	itoa(INT_MIN, str);
	printf("Minimum: %s\n", str);
	itoa(INT_MAX, str);
	printf("Maximum: %s\n", str);
	itob(256, str, 10);
	printf("256 in decimal: %s\n", str);
	itob(256, str, 8);
	printf("256 in octal: %s\n", str);
	itob(256, str, 16);
	printf("256 in hex: %s\n", str);
	itob(256, str, 2);
	printf("256 in binary: %s\n", str);
	itob(256, str, 3);
	printf("256 in ternary: %s\n", str);

	return 0;
}

// The solution I found online was much more elegant than this.
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

void itob(int n, char s[], int b) {
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
		s[i++] = n % b + '0';
	} while ( (n/=b) > 0);

	if (sign < 0)
		s[i++] = '-';

	s[i] = '\0';

	// Slightly more complicated hack, because it might overflow
	if (largest_neg) {
		i = 0;
		while (s[i] == (b-1))
			s[i++] = 0;

		if (s[i] == '-') {
			s[i++] = 1;
			s[i++] = '-';
			s[i++] = '\0';
		}
		else if (s[i] == '\0') {
			s[i++] = 1;
			s[i++] = '\0';
		}
		else
			s[0] += 1;
	}

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