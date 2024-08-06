#include "lists.h"

/**
 * free_listint_safe - frees a linked list
 * @h: pointer to the first node in the linked list
 *
 * Return: number of elements in the freed list
 */
size_t free_listint_safe(listint_t **h)
{
	size_t count = 0;
	int address_diff;
	listint_t *current;

	if (h == NULL || *h == NULL)
		return (0);

	while (*h != NULL)
	{
		address_diff = (uintptr_t)(*h) - (uintptr_t)((*h)->next);
		if (address_diff > 0)
		{
			current = (*h)->next;
			free(*h);
			*h = current;
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

