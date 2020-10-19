#include "sort.h"
/**
 * selection_sort - a selection sort algorithm
 * @array: array to be sorted
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
	unsigned int master, swapper, index;
	int temp;

	if (!array)
		return;
	for (master = 0; master < size - 1; master++)
	{
		index = master;
		for (swapper = master + 1; swapper < size; swapper++)
			if (array[swapper] < array[index])
				index = swapper;
		if (index != master)
		{
			temp = array[index];
			array[index] = array[master];
			array[master] = temp;
			print_array(array, size);
		}
	}
}
