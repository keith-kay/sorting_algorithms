#include "sort.h"
#include <stdio.h>

/ ** 101-file_cocktail_sort * /

/**
 *swap_node - swap a node for his previous one
 *@node: node
 *@list: node list
 *Return: return a pointer to a node which was enter it
 */
listint_t *swap_node(listint_t *node, listint_t **list)
{
	listint_t *back = node->prev, *present = node;
	/*NULL, 19, 48, 9, 71, 13, NULL*/

	back->nxt = present->nxt;
	if (present->nxt)
		present->nxt->prev = back;
	present->nxt = back;
	present->prev = back->prev;
	back->prev = present;
	if (present->prev)
		present->prev->nxt = present;
	else
		*list = present;
	return (present);
}
/**
 *cocktail_sort_list - this is a cocktail sort implementation
 *working on a double linked lists
 *@list: list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *node;
	int swap_done = 1;

	if (list == '\0' || (*list) == '\0' || (*list)->nxt == '\0')
		return;
	node = *list;
	while (swap_done == 1)
	{
		swap_done = 0;
		while (node->nxt)
		{
			if (node->n > node->nxt->n)
			{
				node = swap_node(node->nxt, list);
				swap_done = 1;
				print_list(*list);
			}
			node = node->nxt;
		}
		if (swap_done == 0)
			break;
		swap_done = 0;
		while (node->prev)
		{
			if (node->n < node->prev->n)
			{
				node = swap_node(node, list);
				swap_done = 1;
				print_list(*list);
			}
			else
				node = node->prev;
		}
	}
}
