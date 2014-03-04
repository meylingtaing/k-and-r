/* Write a faster implementation of the bitcount driver */

#include <stdio.h>
#include <stdlib.h>

unsigned int bitcount(unsigned int x);

int main(int argc, char** argv) {
    unsigned int x;
    
    if (argc < 2) {
        printf("Usage: %s binary_number\n", argv[0]);
        return 0;
    }

    x = strtoul(argv[1], NULL, 2);
    printf("%u\n", bitcount(x));

    return 0;
}

unsigned int bitcount(unsigned int x) {
    int count = 0;

    while (x != 0) {
        x &= (x-1);
        count++;
    }

    return count;
}
