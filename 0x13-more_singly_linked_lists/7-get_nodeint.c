#include "lists.h"

/**
 * get_nodeint_at_index - Retrieves the node at a specific index in a
 * linked list.
 * @head: Pointer to the first node in the list.
 * @index: Index of the node to retrieve.
 *
 * Return: Pointer to the node at the specified index, or NULL if not
 * found.
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int counter = 0;
	listint_t *current = head;

	while (current != NULL && counter < index)
	{
		current = current->next;
		counter++;
	}

	return (current);
}

