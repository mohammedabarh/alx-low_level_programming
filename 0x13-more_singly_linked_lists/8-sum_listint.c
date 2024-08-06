#include "lists.h"

/**
 * sum_listint - Computes the total sum of all the data in a listint_t list
 * @head: Pointer to the first node in the linked list
 *
 * Return: Total sum of the data in the list
 */
int sum_listint(listint_t *head)
{
	int total_sum = 0;
	listint_t *current_node = head;

	while (current_node != NULL)
	{
		total_sum += current_node->n;
		current_node = current_node->next;
	}

	return (total_sum);
}

