#include "sort.h"

/**
 * swapNode - swap 2 element in an list
 * @head: head of list
 * @nodeA: node
 * @nodeB: node
 */
void swapNode(listint_t *nodeA, listint_t *nodeB, listint_t **head)
{
	if (nodeA->next)
		nodeA->next->prev = nodeB;
	if (nodeB->prev)
		nodeB->prev->next = nodeA;
	nodeB->next = nodeA->next;
	nodeA->prev = nodeB->prev;
	nodeB->prev = nodeA;
	nodeA->next = nodeB;
	if (nodeA->prev == NULL)
		*head = nodeA;
}


/**
 * insertion_sort_list  - insertion_sort_list
 * @list: doubly liked list
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *sot_tail, *insrt, *nxt;

	if(list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	nxt = *list;
	if (!nxt)
		return;

	while (nxt)
	{
		insrt = nxt;
		sot_tail = nxt->prev;
		while (sot_tail)
		{
			if (sot_tail->n > insrt->n)
			{
				swapNode(insrt, sot_tail, list);
				print_list(*list);
			}
			sot_tail = sot_tail->prev;
		}
		nxt = nxt->next;
	}
}
