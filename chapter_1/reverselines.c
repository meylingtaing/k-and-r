/* Reverses input line by line */

#include <stdio.h>

#define MAXLINE 1000

void reverse(char* str);

int main () {
    int c, len;
    char line[MAXLINE];

    len = 0;

    // Read line by line
    while ((c = getchar()) != EOF) {
        if (c == '\n') {
          line[len] = 0;
          reverse(line);
          printf("%s\n", line);
          len = 0;
        }
        else
            line[len++] = c;
    }

    return 0;
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
