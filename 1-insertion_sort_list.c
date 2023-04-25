#include "sort.h"
/*1-insertion_sort_list.c */

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm.
 * @list: pointer to a pointer to the head of the linked list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *node;

	if (list == NULL || (*list)->next == NULL)
		return;
	node = (*list)->next;
	while (node)
	{
		while ((node->prev) && (node->prev->n > node->n))
		{
			node = swap_node(node, list);
			print_list(*list);
		}
		node = node->next;
	}
}

/**
 * swap_nodes - swaps two adjacent nodes in a doubly linked list.
 * @back: pointer to the node before the current node
 * @current: pointer to the current node
 * @list: pointer to a pointer to the head of the linked list
 *
 * Return: pointer to the new current node
 */

listint_t *swap_node(listint_t *node, listint_t **list)
{
	listint_t *back = node->prev, *current = node;
	/*NULL, 19, 48, 9, 71, 13, NULL*/

	back->next = current->next;
	if (current->next)
		current->next->prev = back;
	current->next = back;
	current->prev = back->prev;
	back->prev = current;
	if (current->prev)
		current->prev->next = current;
	else
		*list = current;
	return (current);
}
