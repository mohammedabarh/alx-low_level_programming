#include "lists.h"

/**
 * get_dnodeint_at_index - Returns the nth node of a doubly linked list.
 * @head: Pointer to the head of the list.
 * @index: Index of the node to return, starting from 0.
 *
 * Return: Pointer to the nth node, or NULL if the node does not exist.
 */

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *cont_node = head;
	unsigned int cont = 0;

	while (cont_node && cont != index)
	{
		cont++;
		cont_node = cont_node->next;
	}
	if (cont_node && cont == index)
		return (cont_node);
	return (NULL);
}
