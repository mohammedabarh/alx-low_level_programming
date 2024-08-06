#include "lists.h"

/**
 * free_listint2 - Releases memory allocated for a linked list
 * @head: Address of the pointer to the first node in the list to be freed
 */
void free_listint2(listint_t **head)
{
	listint_t *current_node;

	if (head == NULL || *head == NULL)
		return;

	while (*head)
	{
		current_node = (*head)->next;
		free(*head);
		*head = current_node;
	}

	*head = NULL;
}

