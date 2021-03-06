#include "sort.h"
/**
 * quick_sort_hoare - a quick sort algorithm
 * @array: array of integers to be sorted
 * @size: size of array
 */
void quick_sort_hoare(int *array, size_t size)
{
	int high = size - 1;
	int low = 0;

	sort(array, low, high, size);
}
/**
 * sort - recursive helper function for quick_sort_hoare
 * @array: array to be sorted
 * @low: lowest placement index to be sorted
 * @high: highest placement index to be sorted
 * @size: size of array
 */
void sort(int *array, int low, int high, size_t size)
{
	int part;

	if (low >= high)
		return;
	part = partition(array, low, high, size);
	sort(array, low, part - 1, size);
	sort(array, part, high, size);
}
/**
 * partition - partitions an array by the placement of the last element
 * @array: array being sorted
 * @high: highest index in array
 * @low: lowest index in array
 * @size: size of array
 * Return: the index of the sorted pivot point
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j = high + 1;

	while (1)
	{
		do
			i++;
		while (array[i] < pivot);
		do
			j--;
		while (array[j] > pivot);
		if (i >= j)
			return (i);
		swap(&array[i], &array[j]);
		print_array(array, size);
	}
}
/**
 * swap - swaps two integers
 * @a: first int
 * @b: second int
 */
void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}
