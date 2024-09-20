#include "lists.h"

/**
 * add_dnodeint - adds a new node at the beginning of a dlistint_t list.
 * @head: double pointer to the first element of the list.
 * @n: integer value to be stored in the new node.
 * Return: address of the new element, or NULL if it failed.
 **/
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
    dlistint_t *new_node = malloc(sizeof(dlistint_t));

    if (new_node == NULL)
        return (NULL);

    /* Initialize the new node */
    new_node->n = n;
    new_node->prev = NULL;

    /* Link the new node to the current head */
    new_node->next = *head;

    /* Update the previous head's prev pointer if it exists */
    if (*head != NULL)
        (*head)->prev = new_node;

    /* Update head to point to the new node */
    *head = new_node;

    return (new_node);
}

