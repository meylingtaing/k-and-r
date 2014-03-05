/* Compare two implementations of binary search */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRSIZE 100000

int binsearch(int x, int v[], int n);
int binsearch_mod(int x, int v[], int n);

int main() {
	int arr[ARRSIZE];
	int i;
	//int book_result, mod_result;
	time_t start, end;
	long book_time, mod_time;

	srand(time(NULL));

	// Fill an array
	for (i = 0; i < ARRSIZE; i++) {
		arr[i] = i*2;
	}

	// Use book's method
	start = time(NULL);
	for (i = 0; i < ARRSIZE*100; i++) {
		binsearch(rand() % (ARRSIZE*2), arr, ARRSIZE);
	}
	end = time(NULL);
	book_time = end-start;

	start = time(NULL);
	for (i = 0; i < ARRSIZE*100; i++) {
		binsearch_mod(rand() % (ARRSIZE*2), arr, ARRSIZE);
	}
	end = time(NULL);
	mod_time = end-start;

	//if (book_result == mod_result) {
		printf("The example in the book took %ld s\n", book_time);
		printf("The modified search took %ld s\n", mod_time);
	//}
	//else
	//	printf("Didn't work\n");

	return 0;
}

/* Implementation from the book */
int binsearch(int x, int v[], int n) {
	int low, high, mid;

	low = 0;
	high = n - 1;

	while (low <= high) {
		mid = (low+high) / 2;

		if (x < v[mid])
			high = mid-1;
		else if (x > v[mid])
			low = mid+1;
		else
			return mid;
	}

	return -1;
}

/* Modified version */
int binsearch_mod(int x, int v[], int n) {
	int low, high, mid;

	low = 0;
	high = n - 1;
	mid = (low+high)/2;

	while (low <= high && x != v[mid]) {

		if (x < v[mid])
			high = mid-1;
		else
			low = mid+1;

		mid = (low+high) / 2;
	}

	if (x == v[mid])
		return mid;
	else
		return -1;
}