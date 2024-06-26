#include "main.h"

/**
 * print_last_digit - Prints the last digit of an integer
 * @a: The number to compute the last digit
 *
 * Return: The value of the last digit
 */
int print_last_digit(int a)
{
	int last_digit = abs(a % 10);

	_putchar(last_digit + '0');
	return (last_digit);
}
