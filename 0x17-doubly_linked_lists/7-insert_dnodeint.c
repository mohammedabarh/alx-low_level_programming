#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a new node at a given position.
 * @h: double pointer to the head of the list.
 * @idx: index where the new node should be added (starts at 0).
 * @n: value to store in the new node.
 *
 * Return: address of the new node, or NULL if it failed.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
    dlistint_t *new, *temp = *h;
    unsigned int i = 0;

    if (idx == 0) /* Insert at the beginning */
        return (add_dnodeint(h, n));

    /* Traverse the list to find the position before the index */
    while (temp && i < idx - 1)
    {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) /* Index is out of range */
        return (NULL);

    if (temp->next == NULL) /* Insert at the end */
        return (add_dnodeint_end(h, n));

    /* Insert in the middle */
    new = malloc(sizeof(dlistint_t));
    if (!new)
        return (NULL);
    new->n = n;
    new->next = temp->next;
    new->prev = temp;
    if (temp->next != NULL)
        temp->next->prev = new;
    temp->next = new;

    return (new);
}

