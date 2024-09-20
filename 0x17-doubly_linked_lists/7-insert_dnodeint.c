#include "lists.h"

/**
 * insert_dnodeint_at_index - Inserts a new node at a given position.
 * @h: Double pointer to the head of the list.
 * @idx: Index where the new node should be added (starts at 0).
 * @n: Data to insert into the new node.
 *
 * Return: Address of the new node, or NULL if it failed.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node, *temp = *h;
	unsigned int i = 0;

	/* Create the new node */
	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = n;

	/* Case: Inserting at the beginning (index 0) */
	if (idx == 0)
		return (add_dnodeint(h, n));

	/* Traverse the list to find the position to insert the node */
	while (temp != NULL && i < idx - 1)
	{
		temp = temp->next;
		i++;
	}

	/* If temp is NULL, the index is out of bounds */
	if (temp == NULL || temp->next == NULL)
	{
		free(new_node);
		return (NULL);
	}

	/* Case: Inserting at the end */
	if (temp->next == NULL)
		return (add_dnodeint_end(h, n));

	/* Insert new node between temp and temp->next */
	new_node->next = temp->next;
	new_node->prev = temp;
	if (temp->next != NULL)
		temp->next->prev = new_node;
	temp->next = new_node;

	return (new_node);
}

