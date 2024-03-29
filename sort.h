#ifndef _SORT_H_
#define _SORT_H_

/* Standard Libraries */
#include <stdio.h>

/* Data structures */

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;


/* Prototype declarations */
void bubble_sort(int *array, size_t size);
listint_t *create_listint(const int *array, size_t size);
void insertion_sort_list(listint_t **list);
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void quick_sort(int *array, size_t size);
void _quick_sort(int *array, size_t sz, ssize_t strt, ssize_t end);
ssize_t _partition(int *array, size_t sz, ssize_t strt, ssize_t end);
void selection_sort(int *array, size_t size);


#endif /* sort header */
