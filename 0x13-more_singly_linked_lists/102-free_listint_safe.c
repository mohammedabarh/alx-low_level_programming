/*
 * File: 102-free_listint_safe.c
 * Auth: Gedeon Obae Gekonge
 */

#include "lists.h"

size_t looped_listint_count(listint_t *head);
size_t free_listint_safe(listint_t **h);

/**
 * looped_listint_count - Determines the number of unique nodes
 *                        in a looped listint_t linked list.
 * @head: Pointer to the head of the listint_t to examine.
 *
 * Return: 0 if the list is not looped.
 *         Otherwise, the count of unique nodes in the loop.
 */
size_t looped_listint_count(listint_t *head)
{
	listint_t *slow, *fast;
	size_t count = 1;

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
				count++;
				slow = slow->next;
				fast = fast->next;
			}

			slow = slow->next;
			while (slow != fast)
			{
				count++;
				slow = slow->next;
			}

			return (count);
		}

		slow = slow->next;
		fast = (fast->next)->next;
	}

	return (0);
}

/**
 * free_listint_safe - Safely frees a listint_t list (can handle loops).
 * @h: Address of the pointer to the head of the listint_t list.
 *
 * Return: The count of nodes that were freed.
 *
 * Description: Sets the head pointer to NULL after freeing the list.
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *current;
	size_t count, i;

	count = looped_listint_count(*h);

	if (count == 0)
	{
		while (*h != NULL)
		{
			current = (*h)->next;
			free(*h);
			*h = current;
			count++;
		}
	}
	else
	{
		for (i = 0; i < count; i++)
		{
			current = (*h)->next;
			free(*h);
			*h = current;
		}

		*h = NULL;
	}

	h = NULL;

	return (count);
}

