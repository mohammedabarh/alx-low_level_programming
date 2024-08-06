#include "lists.h"

/**
 * free_listint_safe - frees a linked list
 * @h: double pointer to the head of the linked list
 *
 * Return: the number of nodes in the freed list
 */
size_t free_listint_safe(listint_t **h)
{
	size_t count = 0;
	int offset;
	listint_t *current_node;

	if (h == NULL || *h == NULL)
		return (0);

	while (*h != NULL)
	{
		offset = (intptr_t)(*h) - (intptr_t)((*h)->next);
		if (offset > 0)
		{
			current_node = (*h)->next;
			free(*h);
			*h = current_node;
			count++;
		}
		else
		{
			free(*h);
			*h = NULL;
			count++;
			break;
		}
	}

	*h = NULL;

	return (count);
}

