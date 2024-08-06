/*
 * File: 102-free_listint_safe.c
 * Auth: Gedeon Obae Gekonge
 */

#include "lists.h"

size_t count_unique_nodes_in_loop(listint_t *head);
size_t safely_free_listint(listint_t **head);

/**
 * count_unique_nodes_in_loop - Counts the number of unique nodes
 *                               in a listint_t list with a loop.
 * @head: Pointer to the head of the listint_t list.
 *
 * Return: The number of unique nodes if there is a loop, otherwise 0.
 */
size_t count_unique_nodes_in_loop(listint_t *head)
{
    listint_t *slow, *fast;
    size_t count = 0;

    if (head == NULL || head->next == NULL)
        return 0;

    slow = head;
    fast = head->next;

    while (fast != NULL)
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

            count++;
            slow = slow->next;
            while (slow != fast)
            {
                count++;
                slow = slow->next;
            }

            return count;
        }

        slow = slow->next;
        fast = fast->next;
        if (fast != NULL)
            fast = fast->next;
    }

    return 0;
}

/**
 * safely_free_listint - Frees a listint_t list, safely handling loops.
 * @head: Double pointer to the head of the listint_t list.
 *
 * Return: The number of nodes freed.
 */
size_t safely_free_listint(listint_t **head)
{
    listint_t *current_node;
    size_t node_count, i;

    node_count = count_unique_nodes_in_loop(*head);

    if (node_count == 0)
    {
        while (*head != NULL)
        {
            current_node = (*head)->next;
            free(*head);
            *head = current_node;
        }
    }
    else
    {
        for (i = 0; i < node_count; i++)
        {
            current_node = (*head)->next;
            free(*head);
            *head = current_node;
        }
        *head = NULL;
    }

    return node_count;
}

