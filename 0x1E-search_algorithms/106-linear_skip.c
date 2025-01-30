#include "search_algos.h"

/**
* linear_skip - Searches for a value in a sorted skip list
* @list: Pointer to head of skip list to search in
* @value: Value to search for
*
* Return: Pointer to first node where value is located, or NULL if not found
*/
skiplist_t *linear_skip(skiplist_t *list, int value)
{
skiplist_t *prev, *curr;

if (list == NULL)
return (NULL);

curr = list;
prev = list;

/* Traverse express lane */
while (curr->express && curr->n < value)
{
prev = curr;
curr = curr->express;
printf("Value checked at index [%lu] = [%d]\n", curr->index, curr->n);
}

/* If we've reached the end of express lane */
if (curr->express == NULL && curr->n < value)
{
prev = curr;
while (curr->next)
curr = curr->next;
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
