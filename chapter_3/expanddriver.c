/* Write function expand(s1, s2) that expands shorthand notation */

// I don't really understand what the exercise is asking for

#include <stdio.h>
#include <ctype.h>

#define NODASH 0
#define DASH 1
#define BUFF 1000

void expand(char* s1, char* s2);

int main(int argc, char** argv) {
    char str[BUFF];

    if (argc < 2) {
        printf("Usage: %s stringtoexpand\n", argv[0]);
        return -1;
    }

    expand(argv[1], str);
    printf("%s\n", str);
    return 0;
}

// Assuming s2 has enough space
// sequences like 'a-b-c' will expand the 'a-b' part not but not 'b-c'
void expand(char* s1, char* s2) {
    char start = s1[0];
    int state = NODASH;
    int i = 1;
    int j = 0;

    // First character is always printed
    s2[j++] = start;

    // Making sure we don't have the empty string
    if (start == 0)
        return;

    while (s1[i] != 0) { 
        if (state == DASH) {
            
            // Super long if for expanding
            // Assuming we're only expanding sequences of 1digit nums
            if ( (isupper(s1[i]) && isupper(start)) ||
                 (islower(s1[i]) && islower(start)) ||
                 (isdigit(s1[i]) && isdigit(start)) ) {

                    char c;
                    // Print ascending
                    if (start < s1[i]) {
                        for (c = start+1; c <= s1[i]; c++)
                            s2[j++] = c;
                    }

                    // Print descending
                    else if (start > s1[i]) {
                        for (c = start-1; c >= s1[i]; c--)
                            s2[j++] = c;
                    }

                    // Print nothing if they're equal

                    start = 0;
            }

            // No expansion
            else {
                s2[j++] = '-';
                s2[j++] = start = s1[i];
            }

            state = NODASH;
        }
        else {
            if (isalnum(s1[i])) {
                s2[j++] = start = s1[i];
            }
            else if (s1[i] == '-')
                state = DASH;
            else
                s2[j++] = s1[i];
        }

        i++;
    }

    // In case we ended with a dash
    if (state == DASH)
        s2[j++] = '-';

    s2[j++] = 0;
}