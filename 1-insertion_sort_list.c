#include "sort.h"
/**
 * insertion_sort_list - an insertion sort algorithm
 * @list: a doubly-linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *marker;

	if (!list || !(*list) || !(*list)->next /*|| !(*list)->next->next*/)
		return;
	current = (*list)->next;
	while (current)
	{
		/*find first inconsistency*/
		while (current->n > current->prev->n)
			current = current->next;
		/*set place marker for reference*/
		marker = current->next;
		/*find where current node belongs*/
		while (current->prev && current->n < current->prev->n)
			node_swap(list, current->prev, current);
		/*rinse and repeat*/
		current = marker;
	}
}
/**
 * node_swap - swaps two adjacent nodes
 * @list: list the nodes are in
 * @a: first sequential node
 * @b: second sequential node
 */
void node_swap(listint_t **list, listint_t *a, listint_t *b)
{
	if (a->prev)
		a->prev->next = b;
	if (b->next)
		b->next->prev = a;
	a->next = b->next;
	b->prev = a->prev;
	b->next = a;
	a->prev = b;
	while ((*list)->prev)
		*list = (*list)->prev;
	print_list(*list);
}
