/*
 * File: 102-free_listint_safe.c
 * Auth: Gedeon Obae Gekonge
 */

#include "lists.h"

size_t looped_listint_count(listint_t *head);
size_t free_listint_safe(listint_t **head_ref);

/**
 * looped_listint_count - Calculates the number of distinct nodes
 *                        in a looped listint_t linked list.
 * @head: A pointer to the beginning of the listint_t list to inspect.
 *
 * Return: 0 if the list has no loop, otherwise the count of unique nodes.
 */
size_t looped_listint_count(listint_t *head)
{
	listint_t *slow_ptr, *fast_ptr;
	size_t count = 1;

	if (head == NULL || head->next == NULL)
		return (0);

	slow_ptr = head->next;
	fast_ptr = (head->next)->next;

	while (fast_ptr != NULL)
	{
		if (slow_ptr == fast_ptr)
		{
			slow_ptr = head;
			while (slow_ptr != fast_ptr)
			{
				count++;
				slow_ptr = slow_ptr->next;
				fast_ptr = fast_ptr->next;
			}

			slow_ptr = slow_ptr->next;
			while (slow_ptr != fast_ptr)
			{
				count++;
				slow_ptr = slow_ptr->next;
			}

			return (count);
		}

		slow_ptr = slow_ptr->next;
		fast_ptr = (fast_ptr->next)->next;
	}

	return (0);
}

/**
 * free_listint_safe - Frees a listint_t list safely (i.e.,
 *                     handles lists with loops).
 * @head_ref: A pointer to the address of the head of the listint_t list.
 *
 * Return: The number of nodes that were freed.
 *
 * Description: The function sets the head to NULL after freeing.
 */
size_t free_listint_safe(listint_t **head_ref)
{
	listint_t *current_node;
	size_t total_nodes, i;

	total_nodes = looped_listint_count(*head_ref);

	if (total_nodes == 0)
	{
		while (*head_ref != NULL)
		{
			current_node = (*head_ref)->next;
			free(*head_ref);
			*head_ref = current_node;
		}
	}
	else
	{
		for (i = 0; i < total_nodes; i++)
		{
			current_node = (*head_ref)->next;
			free(*head_ref);
			*head_ref = current_node;
		}

		*head_ref = NULL;
	}

	head_ref = NULL;

	return (total_nodes);
}

