#include "sort.h"

/**
 * bubble_sort - implements the selection sort algorithm
 * @array: an array of integers
 * @size: number of elements in array
 * Description:
 * - sorts elements of array in ascending order by selection
 * 		sort algorithm.
 * - prints out the array each time there is a swap of elements.
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	int temp;
	size_t i, j, k;

	if (!array || size <= 1)
		return;
	for (i = 0; i < size; i++)
	{
		k = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[k])
				k = j;
		}
		if (k == i)
			continue;

		temp = array[i];
		array[i] = array[k];
		array[k] = temp;
		print_array((const int *)array, size);
	}
}
