#include "lists.h"

/**
 * print_dlistint - prints all the elements of a dlistint_t list
 * @h: head of the list
 * 
 * Return: the number of nodes
 */
size_t print_dlistint(const dlistint_t *h)
{
    size_t count = 0; /* Use size_t for count */

    /* If the list is empty */
    if (h == NULL)
        return (count);

    /* Traverse and print the list */
    while (h != NULL)
    {
        printf("%d\n", h->n);
        count++;
        h = h->next; /* Move to the next node */
    }

    return (count);
}
