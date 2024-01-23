#include "sort.h"

/**
 * insertion_sort_list  - insertion_sort_list
 * @list: doubly liked list
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *sot_tail, *curr, *nxt = *list;

	if (!list || !nxt || !(nxt->next))
		return;

	for (; nxt; nxt = nxt->next)
	{
		curr = nxt;
		sot_tail = nxt->prev;


		while (sot_tail)
		{
			if (sot_tail->n > curr->n)
			{
				if (curr->next)
					 curr->next->prev = sot_tail;
				if (sot_tail->prev)
					sot_tail->prev->next = curr;

				sot_tail->next = curr->next;
				curr->prev = sot_tail->prev;
				curr->next = sot_tail;
				sot_tail->prev = curr;

				if (sot_tail == *list)
					*list = curr;
				print_list((const listint_t *)*list);
			}
			sot_tail = sot_tail->prev;
		}
	}
}
