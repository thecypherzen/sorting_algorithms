#include "sort.h"

/**
 * bubble_sort - implements the bubble sort algorithm
 * @array: an array of integers
 * @size: number of elements in array
 * Description:
 * - sorts array elements in ascending order.
 * - if array is already sorted after first n passes, exit
 * - don't pass over the array if length is 1
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	int temp;
	size_t i, j, sorted = 1;

	if (!array || size <= 1)
		return;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				sorted = 0;
				print_array(array, size);
			}
		}
		/* halt if array is sorted */
		if (sorted)
			return;
	}
}
