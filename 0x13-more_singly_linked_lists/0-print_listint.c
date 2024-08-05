#include "lists.h"

/**
 * print_listint - Outputs all integers from a linked list
 * @h: linked list of type listint_t to output
 *
 * Return: count of nodes
 */
size_t print_listint(const listint_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		count++;
		h = h->next;
	}

	return (count);
}

