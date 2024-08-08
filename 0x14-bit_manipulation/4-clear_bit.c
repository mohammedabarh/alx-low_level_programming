#include "main.h"
#include <limits.h>

/**
 * clear_bit - Sets the value of a bit to 0 at a given index.
 * @n: Pointer to the number to modify.
 * @index: Index of the bit to clear.
 *
 * Return: 1 if successful, -1 if an error occurred.
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int mask;

	if (index >= sizeof(unsigned long int) * CHAR_BIT)
	{
		return (-1);
	}

	/* Create a mask with a 0 at the given index */
	mask = ~(1UL << index);
	*n &= mask;

	return (1);
}

