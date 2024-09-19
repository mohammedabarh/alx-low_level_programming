#include "lists.h"

/**
 * print_dlistint - Prints all the elements of a dlistint_t list.
 * @h: Head of the list.
 *
 * Return: The number of nodes.
 */
size_t print_dlistint(const dlistint_t *h)
{
    size_t count = 0;  /* Use size_t for count */

    if (h == NULL)
        return (count);

    /* Move to the head of the list if not already there */
    while (h->prev != NULL)
        h = h->prev;

    /* Traverse and print the list */
    while (h != NULL)
    {
        printf("%d\n", h->n);
        count++;
        h = h->next;
    }

    return (count);
}
