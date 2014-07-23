/* K&R 7.1
 * Write a program that converts upper case to lower or lower case to upper
 * depending on the name it is invoked with, as found in argv[0]
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int c;

    if (argc >= 2) {
        if (strcmp(argv[1], "lower") == 0) 
            while ((c = getchar()) != EOF)
                putchar(tolower(c));
        else if (strcmp(argv[1], "upper") == 0)
            while ((c = getchar()) != EOF)
                putchar(toupper(c));
        else {
            puts("Argument must be 'upper' or 'lower'");
            return 1;
        }
   }
    else {
        puts("Must supply an argument, either upper or lower");
        return 1;
    }
    return 0;
}
