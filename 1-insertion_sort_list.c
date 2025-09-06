#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 * order using insertion sort
 * @list: to be printed after each swap
 *
 * Return - time complexity
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current)
	{
		next = current->next;

		while (current->prev && current->n < current->prev->n)
		{
			listint_t *prev = current->prev;
			listint_t *tmp_next = current->next;

			prev->next = tmp_next;
			if (tmp_next)
				tmp_next->prev = prev;

			current->prev = prev->prev;
			current->next = prev;

			if (prev->prev)
				prev->prev->next = current;
			else
				*list = current;

			prev->prev = current;

			print_list(*list);
		}

		current = next;
	}
}
