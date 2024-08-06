#include "lists.h"

/**
 * free_listint - Deallocates memory used by a linked list
 * @head: Pointer to the first node in the list to be freed
 */
void free_listint(listint_t *head)
{
	listint_t *current;

	while (head != NULL)
	{
		current = head->next;
		free(head);
		head = current;
	}
}

