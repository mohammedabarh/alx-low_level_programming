#include "lists.h"

/**
 * free_dlistint - Frees a doubly linked list.
 * @head: Pointer to the head of the list.
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *ac_node, *node;

	if (head)
	{
		ac_node = head;
		node = head->next;
		while (node)
		{
			free(ac_node);
			ac_node = node;
			node = node->next;
		}
		free(ac_node);
	}
}
