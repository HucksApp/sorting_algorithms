#include "sort.h"

/**
 * selection_sort - Implementation of selection Sort Algrithme
 * @array: Array to sort type int *
 * @size: The Size of The Given Array
 *
 * Return: (Void) Sorted Array
 */
void selection_sort(int *array, size_t size)
{
	int index, iter, ind, smallest;


	for (index = 0; index < (int)size - 1 ; index++)
	{
		smallest = array[index];
		for (iter = index + 1 ; iter < (int)size; iter++)
			if (array[iter] < smallest)
				smallest = array[iter], ind = iter;

		if (smallest == array[index])
			continue;
		array[ind] = array[index];
		array[index] = smallest;
		print_array(array, size);
	}
}
