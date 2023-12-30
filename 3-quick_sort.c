#include "sort.h"

/**
 * quick_sort - sorts an array using the quick sort algorithm
 * in ascending order
 *
 * Description: it uses two helper functions which it calls
 * recursively
 *
 * @array: the array
 * @size: size of the array
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size <= 0)
		return;

	_quick_sort(array, size, 0, size - 1);
}

/**
 * _quick_sort - a function that calls itself recursively
 *
 * Description: it partitions the array and calls itself
 * to sort each partition
 *
 * @array: the array to sort
 * @sz: the array's size
 * @strt: the starting index of partioning/sorting
 * @end: the end index of the sort/partioning
 *
 * Return: void
 */
void _quick_sort(int *array, size_t sz, ssize_t strt, ssize_t end)
{
	ssize_t sorted_pos;

	if (strt >= end)
		return;
	sorted_pos = _partition(array, sz, strt, end);
	_quick_sort(array, sz, strt, sorted_pos);
	_quick_sort(array, sz, sorted_pos + 1, end);
}


/**
 * _partition - determines the index of the array at which to partion
 *
 * @array: the array
 * @sz: the array size
 * @strt: the starting index of partition
 * @end: the ending index of partition
 *
 * Return: the index of array at which to partition
 */
ssize_t _partition(int *array, size_t sz, ssize_t strt, ssize_t end)
{
	int temp;
	ssize_t pivot;

	pivot = end, --end;
	while (strt < end)
	{
		while (array[strt] <= array[pivot] && strt < end)
			strt++;
		while (array[end] >= array[pivot] && strt < end)
			end--;
		if (strt < end)
		{
			temp = array[strt];
			array[strt] = array[end], array[end] = temp;
			print_array(array, sz);
		}
	}
	if (strt == end && array[end] > array[pivot])
	{
		temp = array[end];
		array[end] = array[pivot], array[pivot] = temp;
		print_array(array, sz);
	}
	return (end);
}
