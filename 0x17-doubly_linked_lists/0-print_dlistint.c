#include "lists.h"

/**
 * print_dlistint - prints all the elements of a dlistint_t list
 *
 * @h: pointer to the head of the list
 * Return: the number of nodes in the list
 */
size_t print_dlistint(const dlistint_t *h)
{
    size_t count = 0;
    const dlistint_t *current = h;

    /* Return zero if the list is empty */
    if (!current)
        return (count);

    /* Navigate to the head of the list */
    while (current->prev)
        current = current->prev;

    /* Print each node's data and count nodes */
    for (; current; current = current->next)
    {
        printf("%d\n", current->n);
        count++;
    }

    return (count);
}

