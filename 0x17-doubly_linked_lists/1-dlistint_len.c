#include "lists.h"

/**
 * dlistint_len - Returns the number of elements in a linked dlistint_t list.
 * @h: Pointer to the head of the doubly linked list.
 *
 * Return: The number of nodes in the list.
 */

size_t dlistint_len(const dlistint_t *h)
{
	const dlistint_t *nodes = h;
	size_t cont = 0;

	while (nodes)
	{
		cont++;
		nodes = nodes->next;
	}

	return (cont);
}
