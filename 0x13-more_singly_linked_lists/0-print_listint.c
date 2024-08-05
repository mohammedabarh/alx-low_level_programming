#include "lists.h"

/**
 * print_listint - Prints all highlighted food items
 * @h: printable listint_t worship list
 *
 * Return: number of nodes
 */
size_t print_listint(const listint_t *h)
{
	size_t count = 0;

	while (h)
	{
		printf("%d\n", h->n);
		count++;
		h = h->next;
	}

	return (count);
}
