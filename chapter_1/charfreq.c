/* Calculate frequencies of different characters in a file and print a
   histogram. I am only doing a horizontal histogram. Also just doing only
   alphabetical characters */

#include <stdio.h>

#define LETTERS 26

int array_max(int arr[], int len);

int main () {
	int c, dash, max;
	int i, j;
	int letter_freq[LETTERS] = {0};

	while ((c = getchar()) != EOF) {

		// Check if it's alphabetical
		if (c >= 'A' && c <= 'Z')
			letter_freq[c - 'A']++;
		else if (c >= 'a' && c <= 'z')
			letter_freq[c - 'a']++;
	}

	// Determine the max and how much each dash represents
    max = array_max(letter_freq, 26);
    dash = letter_freq[max] / 50;
    if (dash == 0)
        dash = 1;

    printf("Frequencies of letters:\n");

    for (i = 0; i < LETTERS; i++) {
        printf("%3c: ", i+'A');
        for (j = 0; j < letter_freq[i]; j+= dash)
            printf("=");
        printf(" (%d)\n", letter_freq[i]);
    }

    return 0;
}

/* Give the index of the array with the highest value. If tie, one is picked */
int array_max(int arr[], int len) {
    int max = arr[0];
    int max_index = 0;
    int i;
    for (i = 1; i < len; i++) {
        if (arr[i] > max) {
            max_index = i;
            max = arr[i];
        }
    }

    return max_index;
}