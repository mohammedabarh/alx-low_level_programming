#include "lists.h"

/**
 * pop_listint - Removes the head node from a linked list
 * @head: Pointer to the first node in the linked list
 *
 * Return: The value of the data from the removed node,
 * or 0 if the list was empty
 */
int pop_listint(listint_t **head)
{
	listint_t *node_to_free;
	int value;

	if (head == NULL || *head == NULL)
		return (0);

	value = (*head)->n;
	node_to_free = (*head)->next;
	free(*head);
	*head = node_to_free;

	return (value);
}

