#include "sort.h"

/**
 * maxNum - Set the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 * @max: Maximum num in the array.
 * 
 */
void maxNum(int *array, size_t size, int *max)
{
	int index;
	*max = array[0];

	for (index = 1; index < (int)size; index++)
		if (array[index] > *max) 
			*max = array[index];/* max */
}

/**
 * counting_sort - Sort an array of integers in ascending order
 *                 using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the counting array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
	int range, max, index;
	int *counts, *sorted;

	if (array == NULL || size < 2)
		return;

	maxNum(array, size, &max);
	range = max + 1; /* 0 to max */

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	counts = (int *)malloc(sizeof(int) * range);
	if(!counts)
	{
		free(sorted);
		return;
	}
	for (index = 0; index < range; index++) 
		counts[index] = 0; /*init counts*/
	for (index = 0; index < (int)size; index++) 
		counts[array[index]]++; /*count occurrence*/
	for (index = 1; index < range; index++)
		/*cummutative counts array */
		counts[index] += counts[index - 1];
	print_array(counts, range);

	for (index = size - 1; index >= 0; counts[array[index]]--, index--)
		 sorted[counts[array[index]] -1] = array[index];

	for (index = 0; index < (int)size; index++)
		array[index] = sorted[index];
	free(counts);
	free(sorted);
}
