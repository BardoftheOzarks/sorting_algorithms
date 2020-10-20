#include "sort.h"
/**
 * quick_sort - a quick sort algorithm
 * @array: array of integers to be sorted
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	int high = size - 1;
	int low = 0;

	sort(array, low, high, size);
}
/**
 * sort - recursive helper function for quick_sort
 * @array: array to be sorted
 * @low: lowest placement index to be sorted
 * @high: highest placement index to be sorted
 */
void sort(int *array, int low, int high, size_t size)
{
	int part;

	if (low >= high)
		return;
	part = partition(array, low, high, size);
	sort(array, low, part - 1, size);
	sort(array, part + 1, high, size);
}
/**
 * partition - partitions an array by the placement of the last element
 * @high: highest index in array
 * @low: lowest index in array
 * Return: the index of the sorted pivot point
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int index = low;
	int j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			if (index != j)
			{
				swap(&array[index], &array[j]);
				print_array(array, size);
			}
			index++;
		}
	}
	if (array[high] < array[index])
	{
		swap(&array[index], &array[high]);
		print_array(array, size);
	}
	return (index);
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
