/*
 * File: 102-free_listint_safe.c
 * Auth: Gedeon Obae Gekonge
 */

#include "lists.h"

size_t looped_listint_count(listint_t *head);
size_t free_listint_safe(listint_t **head_ref);

/**
 * looped_listint_count - Counts the number of unique nodes
 *                      in a looped listint_t linked list.
 * @head: A pointer to the head of the listint_t to check.
 *
 * Return: If the list is not looped - 0.
 *         Otherwise - the number of unique nodes in the list.
 */
size_t looped_listint_count(listint_t *head)
{
    listint_t *slow = head, *fast = head;
    size_t count = 0;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            listint_t *entry = head;

            while (entry != slow)
            {
                count++;
                entry = entry->next;
                slow = slow->next;
            }

            do
            {
                count++;
                slow = slow->next;
            } while (slow != entry);

            return count;
        }
    }

    return 0;
}

/**
 * free_listint_safe - Frees a listint_t list safely (i.e.,
 *                     can free lists containing loops)
 * @head_ref: A pointer to the address of
 *            the head of the listint_t list.
 *
 * Return: The size of the list that was freed.
 *
 * Description: The function sets the head to NULL.
 */
size_t free_listint_safe(listint_t **head_ref)
{
    listint_t *current = *head_ref;
    listint_t *next_node;
    size_t count = 0;

    if (!head_ref || !*head_ref)
        return 0;

    size_t loop_size = looped_listint_count(*head_ref);

    if (loop_size == 0)
    {
        while (current)
        {
            next_node = current->next;
            free(current);
            current = next_node;
            count++;
        }
    }
    else
    {
        for (size_t i = 0; i < loop_size; i++)
        {
            next_node = current->next;
            free(current);
            current = next_node;
            count++;
        }

        // Set the head to NULL after freeing loop nodes
        *head_ref = NULL;
    }

    *head_ref = NULL; // Ensure head_ref points to NULL
    return count;
}

