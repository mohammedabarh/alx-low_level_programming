#include "lists.h"
#include <stdlib.h>

/**
 * add_dnodeint_end - Adds a new node at the end of a dlistint_t list.
 * @head: Pointer to a pointer to the head of the list.
 * @n: Integer value to be stored in the new node.
 *
 * Return: Address of the new element, or NULL if it failed.
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
    dlistint_t *new_node, *last;

    /* Allocate memory for the new node */
    new_node = malloc(sizeof(dlistint_t));
    if (new_node == NULL)
        return NULL;

    /* Initialize the new node */
    new_node->n = n;
    new_node->next = NULL;

    /* If the list is empty, make the new node the head */
    if (*head == NULL)
    {
        new_node->prev = NULL;
        *head = new_node;
        return new_node;
    }

    /* Traverse to the last node */
    last = *head;
    while (last->next != NULL)
        last = last->next;

    /* Connect the new node to the last node */
    last->next = new_node;
    new_node->prev = last;

    return new_node;
}
