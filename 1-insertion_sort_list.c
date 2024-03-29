#include "sort.h"

/**
 * insertion_sort_list - sorts doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: pointer to list head
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *runner;

	if (!list || !(*list) || !(*list)->next)
		return;

	curr = *list;
	while (curr)
	{
		runner = curr->next;
		while (runner && (runner->n > curr->n))
		{
			curr = runner;
			runner = runner->next;
		}
		if (runner && (curr->n > runner->n))
		{
			/* detatch node to insert */
			runner->prev->next = runner->next;
			if (runner->next)
				runner->next->prev = runner->prev;

			/* insertion */
			runner->prev = curr->prev;
			runner->next = curr;
			if (curr->prev)
				curr->prev->next = runner;
			else
				*list = runner;
			curr->prev = runner;
			curr = *list;
			print_list(*list);
		}
		else
			curr = curr->next;
	}
}
