#include "search_algos.h"
#include <math.h>

/**
* jump_search - searches for a value in a sorted array using Jump search
* @array: pointer to the first element of the array
* @size: number of elements in array
* @value: value to search for
* Return: first index where value is located, or -1 if not found
*/
int jump_search(int *array, size_t size, int value)
{
size_t step, prev, curr;

if (!array || size == 0)
return (-1);

/* Calculate step size as square root of array length */
step = sqrt(size);
prev = 0;
curr = step;

/* Jump through array */
printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);
while (curr < size && array[curr] < value)
{
printf("Value checked array[%lu] = [%d]\n", curr, array[curr]);
prev = curr;
curr += step;
}

printf("Value found between indexes [%lu] and [%lu]\n", prev, curr);

/* Linear search in the identified block */
curr = curr < size ? curr : size - 1;
while (prev <= curr)
{
printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);
if (array[prev] == value)
return (prev);
prev++;
}

return (-1);
}
