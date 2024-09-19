#include "lists.h"

/**
 * print_dlistint - Prints all the elements of a dlistint_t list
 * @h: Pointer to the head of the list
 *
 * Return: The number of nodes in the list
 */
size_t print_dlistint(const dlistint_t *h)
{
	const dlistint_t *node = h;
	size_t node_count = 0;

	while (N)
	{
		printf("%i\n", N->n);
		cont++;
		N = N->next;
	}

	return (node_count);
}
