#include "main.h"

/**
 * print_sign - Check the sign of a number
 * @n: The number to be checked
 *
 * Return: 1 if n is greater than 0, 0 if n is 0, -1 if n is less than 0
 */
int print_sign(int n)
{
	int sign;

	if (n > 0)
	{
		sign = 1;
		_putchar('+');
	}
	else if (n < 0)
	{
		sign = -1;
		_putchar('-');
	}
	else
	{
		sign = 0;
		_putchar('0');
	}

	return (sign);
}
