/* Count length of words in a file and print histogram */

#include <stdio.h>

int array_max(int arr[], int len);

int main (int argc, char** argv) {

    int c, len, max, dash;
    int len_freq[10] = {0};
    int i, j;

    int horizontal = 0;

    len = 0;

    // Check for horizontal or vertical graph
    if (argc > 1)
        horizontal = 1;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t' || c == '\r') {
            if (len > 0 && len < 10)
                len_freq[len-1]++;
            else if (len >= 10)
                len_freq[9]++;
            len = 0;
        }

        else
            len++;
    }

    if (len > 0 && len < 10)
        len_freq[len-1]++;
    else if (len >= 10)
        len_freq[9]++;

    // Determine the max and how much each dash represents
    max = array_max(len_freq, 10);
    dash = len_freq[max] / 50;
    if (dash == 0)
        dash = 1;

    printf("Frequencies of words of a certain length:\n");

    if (horizontal) {
        for (i = 0; i < 9; i++) {
            printf("%3d: ", i+1);
            for (j = 0; j < len_freq[i]; j+= dash)
                printf("=");
            printf(" (%d)\n", len_freq[i]);
        }
        printf("10+: ");
        for (j = 0; j < len_freq[i]; j+= dash)
            printf("=");
        printf(" (%d)\n", len_freq[i]);
    }
    else {
        char dash_char[10] = {0};

        // Printing out the numbers first
        for (i = 0; i < 10; i++) 
            printf("%-3d ", len_freq[i]);
        printf("\n");

        // Start with 100
        for (i = 100; i > 0; i--) {
            int no_dash = 1;
            for (j = 0; j < 10; j++) {
                if (len_freq[j]/dash >= i) {
                    dash_char[j] = '#';
                    no_dash = 0;
                }
                else
                    dash_char[j] = ' ';
            }
            if (!no_dash) {
                for (j = 0; j < 10; j++)
                    printf("%c   ", dash_char[j]);
                printf("\n");
            }
        }
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