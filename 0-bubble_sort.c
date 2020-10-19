#include "sort.h"
/**
 * bubble_sort - A bubble sort algorithm
 * @array: an array of integers
 * @size: the size of the array
 */
void bubble_sort(int *array, size_t size)
{
	unsigned long int master, swapper, temp;

	if (!array)
		return;
	for (master = 0; master < size - 1; master++)
	{
		for (swapper = 0; swapper < ((size - master) - 1); swapper++)
		{
			if (array[swapper] > array[swapper + 1])
			{
				temp = array[swapper];
				array[swapper] = array[swapper + 1];
				array[swapper + 1] = temp;
				print_array(array, size);
			}
		}
	}
}
