#include "lists.h"

size_t count_unique_nodes_in_loop(listint_t *head);
size_t safely_free_listint(listint_t **head_ptr);

/**
 * count_unique_nodes_in_loop - Determines the number of unique nodes
 *                               in a circular listint_t linked list.
 * @head: A pointer to the head of the listint_t to evaluate.
 *
 * Return: If the list is not circular - 0.
 *         Otherwise - the count of unique nodes in the list.
 */
size_t count_unique_nodes_in_loop(listint_t *head)
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
 * safely_free_listint - Frees a listint_t list safely (i.e.,
 *                       handles lists that may have loops)
 * @head_ptr: A pointer to the address of
 *            the head of the listint_t list.
 *
 * Return: The total number of nodes that were freed.
 *
 * Description: This function sets the head to NULL.
 */
size_t safely_free_listint(listint_t **head_ptr)
{
	listint_t *current;
	size_t node_count, idx;

	node_count = count_unique_nodes_in_loop(*head_ptr);

	if (node_count == 0)
	{
		while (head_ptr != NULL && *head_ptr != NULL)
		{
			current = (*head_ptr)->next;
			free(*head_ptr);
			*head_ptr = current;
			node_count++;
		}
	}
	else
	{
		for (idx = 0; idx < node_count; idx++)
		{
			current = (*head_ptr)->next;
			free(*head_ptr);
			*head_ptr = current;
		}

		*head_ptr = NULL;
	}

	head_ptr = NULL;

	return (node_count);
}

