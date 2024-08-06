#include "lists.h"

/**
 * add_nodeint - Inserts a new node at the start of a linked list
 * @head: Double pointer to the first node of the list
 * @n: Integer value to be stored in the new node
 *
 * Return: Address of the new node, or NULL if allocation fails
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new_node;

	new_node = malloc(sizeof(listint_t));
	if (!new_node)
		return (NULL);

	new_node->n = n;
	new_node->next = *head;
	*head = new_node;

	return (new_node);
}

