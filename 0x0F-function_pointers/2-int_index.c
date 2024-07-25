#include "function_pointers.h"

/**
 * int_index - searches for an integer
 * @array: input integer array
 * @size: size of the array
 * @cmp: pointer to the function to be used to compare values
 *
 * Return: index of the first element for which the cmp function does not return 0
 *         If no elements match, return -1
 *         If size <= 0, return -1
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	if (array == NULL || cmp == NULL || size <= 0)
	{
		return (-1);
	}

	for (int i = 0; i < size; i++)
	{
		if (cmp(array[i]) != 0)
		{
			return (i);
		}
	}

	return (-1);
}
