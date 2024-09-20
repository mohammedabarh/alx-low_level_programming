#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes the node at index of a dlistint_t list.
 * @head: double pointer to the head of the list.
 * @index: index of the node to delete (starting from 0).
 *
 * Return: 1 if it succeeded, -1 if it failed.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *temp = *head;
	unsigned int i = 0;

	if (*head == NULL)  /* List is empty */
		return (-1);

	if (index == 0)  /* Delete the head node */
	{
		*head = temp->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(temp);
		return (1);
	}

	/* Traverse to the node at the given index */
	while (temp != NULL && i < index)
	{
		temp = temp->next;
		i++;
	}

	if (temp == NULL)  /* Index is out of range */
		return (-1);

	if (temp->next != NULL)  /* Adjust the next node's previous pointer */
		temp->next->prev = temp->prev;

	if (temp->prev != NULL)  /* Adjust the previous node's next pointer */
		temp->prev->next = temp->next;

	free(temp);  /* Free the node */
	return (1);
}

