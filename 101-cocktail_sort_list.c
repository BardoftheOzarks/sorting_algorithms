#include "sort.h"
/**
 * cocktail_sort_list - a cocktail sort algorithm
 * @list: a doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *low = NULL, *high = NULL, *mover = *list;

	if (!list || !(*list) || !(*list)->next)
		return;
	while (1)
	{
		while (mover->next != high)
		{
			if (mover->n > mover->next->n)
				swap_node(list, mover, mover->next);
			else
				mover = mover->next;
		}
		high = mover;
		while (mover->prev != low)
		{
			if (mover->n < mover->prev->n)
				swap_node(list, mover->prev, mover);
			else
				mover = mover->prev;
		}
		low = mover;
		if (low == high || low->prev == high || low->next == high)
			break;
	}
}

/**
 * swap_node - swaps two adjacent nodes in a list
 * @list: a doubly linked list
 * @a: first node
 * @b: second node
 */
void swap_node(listint_t **list, listint_t *a, listint_t *b)
{
	if (a->prev)
		a->prev->next = b;
	else
		*list = b;
	b->prev = a->prev;
	a->prev = b;
	if (b->next)
		b->next->prev = a;
	a->next = b->next;
	b->next = a;
	if (!b->prev)
		*list = b;
	print_list(*list);
}
