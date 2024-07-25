#include "function_pointers.h"

/**
 * int_index - finds the index of the first element that satisfies cmp
 * @array: array of integers to search
 * @size: number of elements in the array
 * @cmp: function pointer to compare elements
 *
 * Return: index of the first element for which cmp returns non-zero.
 *         Returns -1 if size <= 0 or if no elements satisfy cmp.
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int index;

	if (size <= 0 || array == NULL || cmp == NULL)
	{
		return (-1);
	}

	index = 0;
	while (index < size)
	{
		if (cmp(array[index]) != 0)
		{
			return (index);
		}
		index++;
	}

	return (-1);
}

