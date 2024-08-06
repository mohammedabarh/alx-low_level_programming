#include "lists.h"

/**
 * reverse_listint - reverses a linked list
 * @head: pointer to the first node in the list
 *
 * Return: pointer to the first node in the reversed list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *previous = NULL;
	listint_t *following = NULL;

	while (*head)
	{
		following = (*head)->next;
		(*head)->next = previous;
		previous = *head;
		*head = following;
	}

	*head = previous;

	return (*head);
}

