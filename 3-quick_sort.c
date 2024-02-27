#include "sort.h"
int n = 1;
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

	printf("\n[%d]=> start[%ld] | end[%ld]\n", n++, strt, end);
	printf("   ");
	print_array(array, sz);
	if (strt >= end)
		return;
	sorted_pos = _partition(array, sz, strt, end);
	_quick_sort(array, sz, strt, sorted_pos - 1);
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
	ssize_t pivot = array[end], s_pos, runner, e;

	s_pos = runner = strt;
	e = end - 1;
	while (runner <= e && s_pos <= e)
	{
		printf("   runner: %ld(%d) | s_pos: %ld(%d) | pivot: %ld\n",
				runner, array[runner], s_pos, array[s_pos], pivot);
		while (runner <= e && array[runner] >= pivot)
				runner++;
		while (s_pos <= e && array[s_pos] <= pivot)
				s_pos++;


		printf("   runner: %ld(%d) | s_pos: %ld(%d) | pivot: %ld\n",
				runner, array[runner], s_pos, array[s_pos], pivot);
		if (s_pos < runner && runner < e)
		{
			temp = array[s_pos];
			array[s_pos] = array[runner];
			array[runner] = temp;
			printf("   ");
			print_array(array, sz);
		}
	}
	printf("   s_pos last: %ld | runner last: %ld\n", s_pos, runner);
	printf("   ");
	print_array(array, sz);
	return (s_pos);
}
