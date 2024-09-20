#include <stdlib.h>
#include "lists.h"

/**
 * free_dlistint - frees a dlistint_t list.
 * @head: pointer to the head of the list.
 *
 * Description: This function traverses the list and frees each node.
 **/
void free_dlistint(dlistint_t *head)
{
    dlistint_t *temp;

    while (head != NULL)
    {
        temp = head;        /* Store the current node */
        head = head->next;  /* Move to the next node */
        free(temp);         /* Free the stored node */
    }
}
