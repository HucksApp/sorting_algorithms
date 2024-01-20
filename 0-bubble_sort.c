#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending orde
 * @array: the array to be sort
 * @size: the size of the array
 * Big O Details
 *  fn(x) E 0(n2)
 *  Best Case: O(n): check all with list already
 *      in asscending order(no bigger num comes first)
 *
 *  Medium Case: ------
 *  Worst Case:   --------
 *                  O(n2)
*/
void bubble_sort(int *array, size_t size)
{
  int index, endi, temp;

  for (endi = size - 1 ; endi; endi--)
  {
   for (index = 0; index < endi ;  index++)
     if (array[index] > array[index + 1])
     {
       temp = array[index];
       array[index] = array[index + 1];
       array[index + 1] = temp;
       print_array(array, size);
     }
  }
}
