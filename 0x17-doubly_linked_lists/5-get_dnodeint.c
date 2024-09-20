#include "lists.h"

/**
 * get_dnodeint_at_index - returns the nth node of a dlistint_t linked list.
 * @head: pointer to the list.
 * @index: index of the nth node, starting from 0.
 *
 * Return: pointer to the nth node, or NULL if the node doesn't exist.
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
    dlistint_t *node = head;
    unsigned int cont = 0;

    while (node && cont != index)
    {
        cont++;
        node = node->next;
    }

    if (node && cont == index)
        return (node);

    return (NULL);
}

