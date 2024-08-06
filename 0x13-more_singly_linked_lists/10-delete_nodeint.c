#include "lists.h"

/**
 * delete_nodeint_at_index - Removes a node at a specific index from
 * a linked list.
 * @head: Pointer to the pointer of the first node in the list.
 * @index: The position of the node to be removed.
 *
 * Return: 1 on success, -1 if it fails.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *current_node = *head;
	listint_t *node_to_delete = NULL;
	unsigned int count = 0;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		*head = (*head)->next;
		free(current_node);
		return (1);
	}

	while (count < index - 1)
	{
		if (!current_node || !(current_node->next))
			return (-1);
		current_node = current_node->next;
		count++;
	}

	node_to_delete = current_node->next;
	current_node->next = node_to_delete->next;
	free(node_to_delete);

	return (1);
}

