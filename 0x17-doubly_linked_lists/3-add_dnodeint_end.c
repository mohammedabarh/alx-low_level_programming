#include "lists.h"

/**
 * add_dnodeint_end - adds a new node at the end of a dlistint_t list.
 * @head: double pointer to the first element of the list.
 * @n: integer value to set in the new node.
 * 
 * Return: address of the new element, or NULL if it failed.
 **/
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
    dlistint_t *new_node;
    dlistint_t *last_node = *head;

    /* Allocate memory for the new node */
    new_node = malloc(sizeof(dlistint_t));
    if (new_node == NULL)
    {
        return (NULL);  /* Return NULL if memory allocation fails */
    }

    /* Set the values for the new node */
    new_node->n = n;
    new_node->next = NULL;  /* The new node will be the last node */

    /* If the list is empty, set the new node as the head */
    if (*head == NULL)
    {
        new_node->prev = NULL;
        *head = new_node;
    }
    else
    {
        /* Traverse to the end of the list */
        while (last_node->next)
        {
            last_node = last_node->next;
        }
        /* Update pointers to add the new node at the end */
        last_node->next = new_node;
        new_node->prev = last_node;
    }

    return (new_node);  /* Return the address of the new node */
}
