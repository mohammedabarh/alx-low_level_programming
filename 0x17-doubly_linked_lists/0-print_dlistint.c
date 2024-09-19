#include "lists.h"

/**
 * print_dlistint - Prints all elements in a dlistint_t list.
 *
 * @h: Pointer to the head of the list.
 * 
 * Return: The total number of nodes.
 */
size_t print_dlistint(const dlistint_t *h)
{
    size_t count = 0;

    if (h == NULL)
        return (count);

    /* Move to the start of the list */
    while (h->prev != NULL)
        h = h->prev;

    /* Traverse the list and print each node's value */
    while (h != NULL)
    {
        printf("%d\n", h->n);
        count++;
        h = h->next;
    }

    return (count);
}
