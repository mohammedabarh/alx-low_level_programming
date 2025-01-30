#include "search_algos.h"

/**
* jump_search - searches for a value in a sorted array using Jump search
* @array: pointer to the first element of the array
* @size: number of elements in array
* @value: value to search for
* Return: first index where value is located, or -1 if not found
*/
int jump_search(int *array, size_t size, int value)
{
size_t step = sqrt(size);
size_t prev = 0;
size_t curr = 0;

if (array == NULL || size == 0)
return (-1);

while (curr < size && array[curr] < value)
{
printf("Value checked array[%lu] = [%d]\n", curr, array[curr]);
prev = curr;
curr += step;
}

printf("Value found between indexes [%lu] and [%lu]\n", prev, curr);

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
