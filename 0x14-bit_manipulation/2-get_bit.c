#include "main.h"

/**
 * get_bit - Returns the value of a bit at a given index.
 * @n: Number to check bits in.
 * @index: Index at which to check the bit.
 *
 * Return: Value of the bit at index, or -1 if there is an error.
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= (sizeof(unsigned long int) * 8))
	{
		return (-1);
	}

	/* Check if the bit at the given index is set or not */
	if ((n >> index) & 1)
	{
		return (1);
	}

	return (0);
}

