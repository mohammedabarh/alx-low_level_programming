#include "lists.h"
#include <stdio.h>

/**
 * print_dlistint - prints all the elements of a dlistint_t list.
 * @h: pointer to the head of the list.
 * Return: the number of nodes.
 **/
size_t print_dlistint(const dlistint_t *h)
{
    const dlistint_t *current_node = h;
    size_t count = 0;

    if (current_node == NULL)
        return (0);

    /* Move to the head if not already there */
    while (current_node->prev)
        current_node = current_node->prev;

    /* Traverse the list and print node values */
    while (current_node)
    {
        printf("%i\n", current_node->n);
        count++;
        current_node = current_node->next;
    }

    return (count);
}

