#include <stdlib.h>
#include "lists.h"

/**
 * add_dnodeint - Adds a new node at the beginning of a dlistint_t list
 * @head: Pointer to a pointer to the head of the list
 * @n: Integer to be included in the new node
 *
 * Return: Address of the new element, or NULL if it failed
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
    dlistint_t *new_node;

    /* Allocate memory for the new node */
    new_node = malloc(sizeof(dlistint_t));
    if (new_node == NULL)
        return NULL;

    /* Initialize the new node */
    new_node->n = n;
    new_node->prev = NULL;
    new_node->next = *head;

    /* If the list is not empty, update the previous pointer of the old head */
    if (*head != NULL)
        (*head)->prev = new_node;

    /* Update the head to point to the new node */
    *head = new_node;

    return new_node;
}
