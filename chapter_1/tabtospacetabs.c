/* Converts	input's	tabs to	space */

#include <stdio.h>

#define	TABSTOP	4

int	main ()	{
	int	spaces_needed =	TABSTOP;
	int	c, i;

	while (	(c=getchar()) != EOF) {

		if (c == '\t') {
			for	(i = 0;	i <	spaces_needed; i++)
				putchar(' ');
			spaces_needed =	TABSTOP;
		}
		else {
			putchar(c);
			
			if (c == '\n')
				spaces_needed =	TABSTOP;
			else {
				spaces_needed--;
				if (spaces_needed == 0)
					spaces_needed =	TABSTOP;
			}
		}
	}
	return 0;
}

