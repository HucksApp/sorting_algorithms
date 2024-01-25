#include "sort.h"
/**
 * shell_sort -Sort an array using shell_sort algorithm
 * @array: array
 * @size: size of the array
 * Return: NULL
 **/
void shell_sort(int *array, size_t size)
{
	unsigned int index, back_index, gap = 1;
	int temp;

	if (array == NULL || size < 2)
		return;

	while (gap < size / 3)
		gap = gap * 3 + 1;

	for (; gap > 0; gap /= 3)
	{
		for (index = gap; index <= size; index += gap)
		{
			back_index = index;
			while (back_index >= gap && array[back_index] < array[back_index - gap])
			{
				temp = array[back_index];
				array[back_index] = array[back_index - gap];
				array[back_index - gap] = temp;
				back_index -= gap;
			}
		}
		print_array(array, size);
	}
}
