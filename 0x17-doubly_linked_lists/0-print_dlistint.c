#include "lists.h"

/**
 * print_dlistint - Prints all elements of a dlistint_t list.
 *
 * @h: Pointer to the head of the doubly linked list.
 * Return: The total number of nodes printed.
 */
size_t print_dlistint(const dlistint_t *h)
{
    size_t node_count = 0;

    /* Check if the list is empty */
    if (h == NULL)
    {
        return (0);
    }

    /* Traverse to the start of the list */
    while (h->prev)
    {
        h = h->prev;
    }

    /* Iterate through each node and print its value */
    while (h)
    {
        printf("%d\n", h->n);
        node_count++;
        h = h->next;
    }

    return (node_count);
}
