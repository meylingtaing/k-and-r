/* Converts input's tabs to space */

/* Allow user to input number of spaces for a tab in command line arg */

#include <stdio.h>
#include <stdlib.h>

#define TABSTOP 4

int main (int argc, char **argv) {
    int tabstop = TABSTOP;
    int spaces_needed;
    int c, i;

    if (argc > 1)
        tabstop = atoi(argv[1]);

    spaces_needed = tabstop;

    while ( (c=getchar()) != EOF) {

        if (c == '\t') {
            for (i = 0; i < spaces_needed; i++)
                putchar(' ');
            spaces_needed = tabstop;
        }
        else {
            putchar(c);
            
            if (c == '\n')
                spaces_needed = tabstop;
            else {
                spaces_needed--;
                if (spaces_needed == 0)
                    spaces_needed = tabstop;
            }
        }
    }
    return 0;
}

