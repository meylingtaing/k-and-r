/* Super simple memory allocation */

#define ALLOCSIZE 10000 // Size of available space

static char allocbuf[ALLOCSIZE]; // Storage for alloc
static char *allocp = allocbuf;	  // Next free position

char *alloc(int n)
{
	if (allocbuf + ALLOCSIZE - allocp >= n) {
		allocp += n;
		return allocp - n;
	}
	else
		return 0;
}

void afree(char *p)
{
	if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
		allocp = p;
}