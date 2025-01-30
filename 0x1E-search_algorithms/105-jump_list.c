#include "search_algos.h"
#include <math.h>

/**
 * jump_list - Searches for a value in a sorted list using Jump search
 * @list: Pointer to head of list to search in
 * @size: Number of nodes in list
 * @value: Value to search for
 *
 * Return: Pointer to first node where value is located, or NULL if not found
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
    size_t step, step_size;
    listint_t *prev, *curr;

    if (list == NULL || size == 0)
        return (NULL);

    step = sqrt(size);
    prev = list;
    curr = list;

    /* Jump forward */
    while (curr->next != NULL && curr->n < value)
    {
        prev = curr;
        step_size = step;
        while (step_size > 0 && curr->next != NULL)
        {
            curr = curr->next;
            step_size--;
        }
        printf("Value checked at index [%lu] = [%d]\n", curr->index, curr->n);
    }

    printf("Value found between indexes [%lu] and [%lu]\n",
           prev->index, curr->index);

    /* Linear search in the block */
    while (prev && prev->index <= curr->index)
    {
        printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);
        if (prev->n == value)
            return (prev);
        prev = prev->next;
    }

    return (NULL);
}
