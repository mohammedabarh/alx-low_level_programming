#include "lists.h"

/**
 * print_dlistint - prints all the elements of a dlistint_t list.
 * @h: pointer to the list.
 * Return: number of nodes.
 **/
size_t print_dlistint(const dlistint_t *h)
{
    const dlistint_t *node = h;
    size_t cont = 0;

    if (node == NULL)  /* Check for empty list */
    {
        return (cont);  /* Return 0 if the list is empty */
    }

    while (node)
    {
        printf("%i\n", node->n);
        cont++;
        node = node->next;
    }

    return (cont);
}
