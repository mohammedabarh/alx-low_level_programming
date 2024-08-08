#include "main.h"

/**
 * _pow - func calculates (base ^ power)
 * @base: base of the exponent
 * @power: power of the exponent
 *
 * Return: value of (base ^ power)
 */
unsigned long int _pow(unsigned int base, unsigned int power)
{
	unsigned long int num = 1;

	while (power--)
		num *= base;

	return (num);
}

/**
 * print_binary - prints a number in binary notation
 * @n: number to print
 *
 * Return: void
 */
void print_binary(unsigned long int n)
{
	unsigned long int mask = _pow(2, sizeof(unsigned long int) * 8 - 1);
	unsigned char printed = 0;

	while (mask)
	{
		if (n & mask)
		{
			_putchar('1');
			printed = 1;
		}
		else if (printed || mask == 1)
			_putchar('0');

		mask >>= 1;
	}
}
