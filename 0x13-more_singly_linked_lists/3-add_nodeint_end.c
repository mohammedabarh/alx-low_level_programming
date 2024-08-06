#include "lists.h"

/**
 * add_nodeint_end - Appends a new node at the end of a linked list
 * @head: Pointer to the head pointer of the list
 * @n: Value to store in the new node
 *
 * Return: Address of the new node, or NULL if memory allocation fails
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new_node;
	listint_t *current = *head;

	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->next = NULL;

	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}

	while (current->next != NULL)
		current = current->next;

	current->next = new_node;

	return (new_node);
}

