#include "lists.h"
#include <stdio.h>

/**
 * listint_len - Calculates the number of nodes
 *               in a listint_t linked list.
 * @h: Pointer to the first node of the listint_t list.
 *
 * Return: The number of nodes in the listint_t list.
 */
size_t listint_len(const listint_t *h)
{
	size_t number = 0;

	while (h != NULL)
	{
		number++;
		h = h->next;
	}

	return (number);  /* Added parentheses here */
}

