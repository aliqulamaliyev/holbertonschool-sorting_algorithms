#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list using insertion sort
 * @list: Double pointer to head of list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (!list || !*list || !(*list)->next)
		return;

	current = (*list)->next;
	while (current)
	{
		temp = current;
		current = current->next;

		while (temp->prev && temp->n < temp->prev->n)
		{
			listint_t *before = temp->prev;
			listint_t *after = temp->next;

			if (before->prev)
				before->prev->next = temp;
			else
				*list = temp;

			temp->prev = before->prev;
			temp->next = before;
			before->prev = temp;
			before->next = after;

			if (after)
				after->prev = before;

			print_list(*list);
		}
	}
}
