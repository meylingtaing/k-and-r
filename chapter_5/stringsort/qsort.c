#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/* qsort: sort v[left] to v[right] into increasing order */
void my_qsort(void *v[], int left, int right, int (*comp)(void *, void *))
{
	int i, last;
	void swap(void *v[], int i, int j);

	// If there's nothing to sort
	if (left >= right)
		return;

	// Move partition element to the front
	swap(v, left, (left+right)/2);

	last = left;
	for (i = left+1; i <= right; i++) {
		if ((*comp)(v[i], v[left]) < 0)
			swap(v, ++last, i);
	}

	// Restore partition to middle
	swap(v, left, last);

	// Sort the two halves
	my_qsort(v, left, last-1, comp);
	my_qsort(v, last+1, right, comp);
}

/* swap: interchange v[i] and v[j] */
void swap(void *v[], int i, int j)
{
	void *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

/* numcmp: compare s1 and s2 numerically */
int numcmp(char *s1, char *s2)
{
	double v1 = atof(s1);
	double v2 = atof(s2);

	if (v1 < v2)
		return -1;
	else if (v1 > v2)
		return 1;
	else
		return 0;
}

/* ignorecasecmp: compare s1 and s2 but ignore case sensitivity */
int ignorecasecmp(char *s1, char *s2)
{
	char c1, c2;
	int i = 0;

	while ( (c1 = toupper(s1[i])) == (c2 = toupper(s2[i])) ) {
		if (c1 == 0)
			return 0;
		i++;
	}

	return (c1 - c2);
}