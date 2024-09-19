#include "lists.h"

/**
 * print_dlistint - Outputs all elements of a dlistint_t list.
 * @h: Pointer to the head of the list.
 * 
 * Return: The total number of nodes in the list.
 **/
size_t print_dlistint(const dlistint_t *h)
{
    size_t count = 0;                /* Initialize node counter */
    const dlistint_t *current_node = h; /* Pointer to traverse the list */

    while (current_node != NULL)      /* Traverse until the end of the list */
    {
        printf("%d\n", current_node->n); /* Print the current node's value */
        count++;                        /* Increment the node count */
        current_node = current_node->next; /* Move to the next node */
    }

    return (count);                   /* Return the total count */
}
