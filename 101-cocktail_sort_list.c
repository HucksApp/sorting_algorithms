#include "sort.h"

/**
 * DLNodeSwap - function swaps double linked nodes
 * @list: head of list
 * @NodeA: pointer to node A
 * @NodeB: pointer to node B
 */
void DLNodeSwap(listint_t **list, listint_t *NodeA, listint_t *NodeB)
{
	if (NodeA->prev)
		NodeA->prev->next = NodeB;
	if (NodeB->next)
		NodeB->next->prev = NodeA;
	NodeB->prev =  NodeA->prev;
	NodeA->next = NodeB->next;
	NodeA->prev = NodeB;
	NodeB->next = NodeA;

	if (NodeB->prev == NULL)
		*list = NodeB;
}


/**
 *  cocktail_sort_list - function sorts a doubly linked list using
 *  the cocktail sort algorithm
 * @list: pointer to list
 */
void cocktail_sort_list(listint_t **list)
{
	int not_sorted;
	listint_t *curr;

	if (!list || !(*list) || !(*list)->next)
		return;

	do {
		not_sorted = 0;
		curr = *list;

		while (curr && curr->next)
		{
			if (curr->n > curr->next->n)
			{
				not_sorted = 1;
				DLNodeSwap(list, curr, curr->next);
				print_list(*list);
			}
			else
				curr = curr->next;
		}

		if (!not_sorted) /* list is sorted*/
			break;

		while (curr && curr->prev)
		{
			if (curr->n < curr->prev->n)
			{
				not_sorted = 1;
				DLNodeSwap(list, curr->prev, curr);
				print_list(*list);
			}
			else
				curr = curr->prev;
		}
	} while (not_sorted);
}
