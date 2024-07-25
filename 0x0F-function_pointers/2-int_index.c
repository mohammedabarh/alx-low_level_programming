#include "function_pointers.h"

/**
 * int_index - Finds the index of the first element in an array for which
 *             a comparison function does not return 0.
 * @array: The array of integers to search.
 * @size: The number of elements in the array.
 * @cmp: A pointer to the function used to compare values.
 *
 * Return: The index of the first element where the comparison function
 *         does not return 0. If no element matches or if size <= 0,
 *         return -1. If array or cmp is NULL, return -1.
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	if (array == NULL || cmp == NULL || size <= 0)
	{
		return (-1);
	}

	for (int i = 0; i < size; ++i)
	{
		if (cmp(array[i]))
		{
			return (i);
		}
	}

	return (-1);
}

