#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * create_node - creates a new node with the given string
 * @str: string to put in the new node
 *
 * Return: address of the new node, or NULL if it fails
 */
static list_t *create_node(const char *str)
{
	list_t *new_node;

	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
	{
		return (NULL);
	}

	new_node->str = strdup(str);
	if (new_node->str == NULL)
	{
		free(new_node);
		return (NULL);
	}

	new_node->len = strlen(str);
	new_node->next = NULL;

	return (new_node);
}

/**
 * add_node_end - adds a new node at the end of a list_t linked list
 * @head: double pointer to the list_t list
 * @str: string to put in the new node
 *
 * Return: address of the new element, or NULL if it failed
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *last_node;

	if (*head == NULL)
	{
		*head = create_node(str);
		return (*head);
	}

	last_node = *head;
	while (last_node->next != NULL)
	{
		last_node = last_node->next;
	}

	last_node->next = create_node(str);
	return (last_node->next);
}

