#include "lists.h"
#include <stdio.h>

/**
 * listint_len - Calculates the number of nodes
 *               in a listint_t linked list.
 * @h: Pointer to the first node of the listint_t list.
 *
 * Return: The count of nodes in the listint_t list.
 */
size_t listint_len(const listint_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		count++;
		h = h->next;
	}

	return (count);  /* Added parentheses here */
}

