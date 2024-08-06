/*
 * File: 102-free_listint_safe.c
 * Auth: Gedeon Obae Gekonge
 */

#include "lists.h"

size_t count_unique_looped_nodes(listint_t *head);
size_t safe_free_listint(listint_t **head_ptr);

/**
 * count_unique_looped_nodes - Counts unique nodes in a looped
 *                              listint_t linked list.
 * @head: Pointer to the start of the listint_t list.
 *
 * Return: If there is no loop - 0.
 *         Otherwise - number of unique nodes in the looped list.
 */
size_t count_unique_looped_nodes(listint_t *head)
{
	listint_t *slow, *fast;
	size_t unique_nodes = 1;

	if (head == NULL || head->next == NULL)
		return (0);

	slow = head->next;
	fast = (head->next)->next;

	while (fast)
	{
		if (slow == fast)
		{
			slow = head;
			while (slow != fast)
			{
				unique_nodes++;
				slow = slow->next;
				fast = fast->next;
			}

			slow = slow->next;
			while (slow != fast)
			{
				unique_nodes++;
				slow = slow->next;
			}

			return (unique_nodes);
		}

		slow = slow->next;
		fast = (fast->next)->next;
	}

	return (0);
}

/**
 * safe_free_listint - Frees a listint_t list safely, handling loops.
 * @head_ptr: Pointer to the address of the head of the listint_t list.
 *
 * Return: Number of nodes that were freed.
 *
 * Description: Function sets the head pointer to NULL.
 */
size_t safe_free_listint(listint_t **head_ptr)
{
	listint_t *current_node;
	size_t total_nodes, i;

	total_nodes = count_unique_looped_nodes(*head_ptr);

	if (total_nodes == 0)
	{
		while (*head_ptr != NULL)
		{
			current_node = (*head_ptr)->next;
			free(*head_ptr);
			*head_ptr = current_node;
		}
	}
	else
	{
		for (i = 0; i < total_nodes; i++)
		{
			current_node = (*head_ptr)->next;
			free(*head_ptr);
			*head_ptr = current_node;
		}

		*head_ptr = NULL;
	}

	head_ptr = NULL;

	return (total_nodes);
}

