#include "function_pointers.h"

/**
 * int_index - Returns the index of the first element for which the
 *             comparison function does not return 0.
 * @array: The array to search.
 * @size: The number of elements in the array.
 * @cmp: A pointer to the comparison function.
 *
 * Return: The index of the first matching element, or -1 if no match
 *         is found, or if the array or cmp is NULL, or if size is
 *         less than or equal to 0.
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	if (array && cmp && size > 0)
	{
		for (int i = 0; i < size; i++)
		{
			if (cmp(array[i]))
				return (i);
		}
	}

	return (-1);
}

