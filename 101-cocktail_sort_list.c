#include "sort.h"

/**
 * swap - Swaps 2 nodes
 * @head: the list
 * @n1: node 1
 * @n2: node 2
 */
void swap(listint_t **head, listint_t *n1, listint_t *n2)
{
	listint_t *p, *n;

	p = n1->prev;
	n = n2->next;

	if (p)
		p->next = n2;
	else
		*head = n2;
	if (n)
		n->prev = n1;

	n2->prev = p;
	n1->next = n;
	n2->next = n1;
	n1->prev = n2;
}

/**
 * cocktail_sort_list - sorts a linked list with cocktail algo
 * @list: the list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *ptr;
	int s = 1;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	ptr = *list;
	while (s)
	{
		s = 0;
		while (ptr->next != NULL)
		{
			if (ptr->n > ptr->next->n)
			{
				swap(list, ptr, ptr->next);
				print_list(*list);
				s = 1;
			}
			else
				ptr = ptr->next;
		}
		if (!s)
			break;
		while (ptr->prev != NULL)
		{
			if (ptr->n < ptr->prev->n)
			{
				swap(list, ptr->prev, ptr);
				print_list(*list);
				s = 1;
			}
			else
				ptr = ptr->prev;
		}
	}
}
