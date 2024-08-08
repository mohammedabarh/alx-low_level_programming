#include "main.h"

/**
 * binary_to_uint - converts a binary string to an unsigned integer.
 * @b: a pointer to the string representing a binary number
 *
 * Return: the decimal value of the binary number, or 0 if invalid input
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;
	int i;

	if (b == NULL)
		return (0);

	for (i = 0; b[i] != '\0'; i++)
	{
		if (b[i] != '0' && b[i] != '1')
			return (0);
	}

	for (i = 0; b[i] != '\0'; i++)
	{
		result = (result << 1) | (b[i] - '0');
	}

	return (result);
}

