/* Determine ranges of different variable types.
 * Trying not to use shift operations, since they weren't even covered yet
 * up to this point. 
 * TODO: Compute the floating point ranges */

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {

	int int_min, int_max;
    unsigned int uint_max;
    short short_min, short_max;
    unsigned short ushort_max;
    char char_min, char_max;
    signed char schar_min, schar_max;
    unsigned long ulong_max;
    long long_min, long_max;

	printf("Ranges from standard header:\n");
	printf("\tchar:  %d to %d\n", CHAR_MIN, CHAR_MAX);
    printf("\tschar: %d to %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("\tushrt: %u to %u\n", 0, USHRT_MAX);
	printf("\tshort: %d to %d\n", SHRT_MIN, SHRT_MAX);
    printf("\tuint:  %u to %u\n", 0, UINT_MAX);
	printf("\tint:   %d to %d\n", INT_MIN, INT_MAX);
    printf("\tulong: %u to %lu\n", 0, ULONG_MAX);
	printf("\tlong:  %ld to %ld\n", LONG_MIN, LONG_MAX);
    printf("\tfloat: %f to %f\n", FLT_MIN, FLT_MAX);
    printf("\tdbl:   %lf to %lf\n", DBL_MIN, DBL_MAX);
    printf("\tldbl:  %llf to %llf\n", LDBL_MIN, LDBL_MAX);

	printf("Ranges from computing:\n");

    // Char is always positive according to this machine/compiler, so I could
    // have just done 
    // char_max = 0; char_max--;
    // but I guess that might not be true on another machine.
    char_max = 2;
    while (char_max > 0)
        char_max *= 2;
    char_max--;
    char_min = 0 - char_max - 1;
    printf("\tchar:  %d to %d\n", char_min, char_max);

    schar_max = 2;
    while (schar_max > 0)
        schar_max *= 2;
    schar_max--;
    schar_min = 0 - schar_max - 1;
    printf("\tschar: %d to %d\n", schar_min, schar_max);

    // Unsigned is simple
    ushort_max = 0;
    ushort_max--;
    printf("\tushrt: %u to %u\n", 0, ushort_max);

    // Calculating short
    short_max = 2;
    while (short_max > 0)
        short_max *= 2;
    short_max--;
    short_min = 0 - short_max - 1;
    printf("\tshort: %d to %d\n", short_min, short_max);
    
    uint_max = 0;
    uint_max--;
    printf("\tuint:  %u to %u\n", 0, uint_max);

    // Calculating max integer by multiplying by 2 until we hit negatives
    int_max = 2;
	while (int_max > 0)
	    int_max *= 2;
    int_max--;

    // Minimum is same magnitude +1
    int_min = 0 - int_max - 1;
	printf("\tint:   %d to %d\n", int_min, int_max);

    ulong_max = 0;
    ulong_max--;
    printf("\tulong: %u to %lu\n", 0, ulong_max);

    // Calculating long
    long_max = 2;
    while (long_max > 0)
        long_max *= 2;
    long_max--;
    long_min = 0 - long_max - 1;
    printf("\tlong:  %ld to %ld\n", long_min, long_max);

	return 0;

}
