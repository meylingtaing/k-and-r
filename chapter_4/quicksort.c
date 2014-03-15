/* Quicksort */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define ARRSIZE 100

void my_qsort_r(int arr[], int left, int right);
void print_arr(int arr[], int len);

int main() 
{
	int arr[ARRSIZE];
	int i;

	srand(time(NULL));
	for (i = 0; i < ARRSIZE; i++)
		arr[i] = rand() % 1000;

	puts("Unsorted: ");
	print_arr(arr, ARRSIZE);

	my_qsort_r(arr, 0, ARRSIZE-1);
	puts("Sorted");
	print_arr(arr, ARRSIZE);

	return 0;
}

void print_arr(int arr[], int len) 
{
	int i;
	for (i = 0; i < len; i++)
		printf("%d ", arr[i]);

	putchar('\n');
}

void my_qsort_r(int arr[], int left, int right) 
{
	int i, curr;
	void swap(int arr[], int i, int j);

	// Array contains less than two items, so already sorted
	if (left >= right)
		return;

	// Move partition item to arr[0]
	swap(arr, left, (left+right)/2);

	// Move items less than partition to left
	curr = left;
	for (i = left + 1; i <= right; i++) {
		if (arr[i] < arr[left])
			swap(arr, ++curr, i);
	}

	// Restore partition element
	swap(arr, left, curr);

	// Recursive calls
	my_qsort_r(arr, left, curr);
	my_qsort_r(arr, curr+1, right);
}

void swap(int arr[], int i, int j) 
{
	int temp;

	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}