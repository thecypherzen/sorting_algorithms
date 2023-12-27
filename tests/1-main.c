#include <stdio.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	listint_t *list;
	int array[] = {10};
	size_t n = sizeof(array) / sizeof(array[0]);

	list = create_listint(array, n);
	if (!list)
		return (1);
	print_list(list);
	printf("\n");
	insertion_sort_list(&list);
	printf("\n");
	print_list(list);
	return (0);
}
