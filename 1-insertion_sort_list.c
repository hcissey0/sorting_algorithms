#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list
 *
 * @list: Pointer to the head of the list
 *
 * Return: void
 */
void insertion_sort_list_0(listint_t **list)
{
	listint_t *tmp, *ptr, *prev;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	ptr = (*list)->next;
	while (ptr)
	{
		prev = ptr->prev;
		while (prev && (prev->n) > (ptr->n))
		{
			tmp = prev->prev;
			if (prev->prev)
				prev->prev->next = ptr;
			else
				*list = ptr;
			prev->next = ptr->next;
			prev->prev = ptr;
			ptr->next = prev;
			ptr->prev = tmp;
			prev = tmp;
			print_list(*list);
		}
		ptr = ptr->next;
	}
}

void insertion_sort_list(listint_t **list)
{
	listint_t *ptr, *tmp, *tmp2;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	ptr = (*list)->next;
	while (ptr)
	{
		tmp = ptr->prev;
		tmp2 = ptr;
		while (tmp && (tmp->n) > (tmp2->n))
		{
			if (tmp->prev)
			{
				tmp->next = tmp2->next;
				tmp2->prev = tmp->prev;

				tmp->prev->next = tmp2;
				if (tmp2->next)
					tmp2->next->prev = tmp;

				tmp->prev = tmp2;
				tmp2->next = tmp;
			}
			else
			{
				tmp2->prev = tmp->prev;
				tmp->next = tmp2->next;
				if (tmp2->next)
					tmp2->next->prev = tmp;
				tmp2->next = tmp;
				tmp->prev = tmp2;
				*list = tmp2;
			}

			print_list(*list);
			tmp = tmp2->prev;
		}
		ptr = ptr->next;
	}
}
