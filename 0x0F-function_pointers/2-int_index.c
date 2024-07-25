#include "function_pointers.h"

/**
 * int_index - searches for an integer in an array
 * @array: array of integers
 * @size: number of elements in the array
 * @cmp: pointer to the function to be used to compare values
 *
 * Return: index of the first element for which cmp function does not return 0,
 *         or -1 if no element matches or size is non-positive
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	if (array && cmp && size > 0)
	{
		for (int i = 0; i < size; i++)
		{
			if (cmp(array[i]))
			{
				return (i);
			}
		}
	}
	return (-1);
}
