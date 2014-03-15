/* Recursive version of reverse(s). Using the same driver from chapter 1 */

#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

void reverse(char str[]);

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

void reverse(char str[]) 
{
    void reverse_r(char str[], int len);
    reverse_r(str, strlen(str));
}

void reverse_r(char str[], int len) {
    int temp;

    if (len <= 1)
        return;
    
    // Reverse everything but the first and last character
    reverse_r(str + 1, len - 2);

    // Swap first and last
    temp = str[0];
    str[0] = str[len-1];
    str[len-1] = temp;
}