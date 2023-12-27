#include "sort.h"

/**
 * insertion_sort_list - sorts doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: pointer to list head
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *runner, *temp, *i_node;

	if (!list || !(*list) || !(*list)->next)
		return;

	curr = *list;
	while(curr->next)
	{
		runner = curr->next;
		while (runner && (runner->n > curr->n))
			runner = runner->next;
		if (runner)
		{
			/* get node to insert */
			i_node = curr;
			while (i_node->prev && i_node->prev->n > runner->n)
				i_node = i_node->prev;
			temp = runner;
			runner = runner->next;

			/* detatch node to insert */
			if (temp->prev)
				temp->prev->next = runner;
			if (runner)
				runner->prev = temp->prev;

			/* insertion */
			temp->prev = i_node->prev;
			temp->next = i_node;
			if (i_node->prev)
				i_node->prev->next = temp;
			else
				*list = temp;
			i_node->prev = temp;
			print_list(*list);
		}
		else
			curr = curr->next;
	}
}
