/*
 * File: 103-find_loop.c
 * Auth: Gedeon Obae Gekonge
 */

#include "lists.h"

/**
 * find_listint_loop - Detects the loop in a listint_t linked list.
 * @head: Pointer to the start of the listint_t list.
 *
 * Return: NULL if no loop is present.
 *         Otherwise, the node where the loop begins.
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow_ptr, *fast_ptr;

	if (head == NULL || head->next == NULL)
		return (NULL);

	slow_ptr = head->next;
	fast_ptr = (head->next)->next;

	while (fast_ptr)
	{
		if (slow_ptr == fast_ptr)
		{
			slow_ptr = head;

			while (slow_ptr != fast_ptr)
			{
				slow_ptr = slow_ptr->next;
				fast_ptr = fast_ptr->next;
			}

			return (slow_ptr);
		}

		slow_ptr = slow_ptr->next;
		fast_ptr = (fast_ptr->next)->next;
	}

	return (NULL);
}

