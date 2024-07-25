#include "3-calc.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * op_add - adds two numbers.
 * @a: first number.
 * @b: second number.
 *
 * Return: sum of a and b.
 */
int op_add(int a, int b)
{
	return (a + b);
}

/**
 * op_sub - subtracts the second number from the first number.
 * @a: first number.
 * @b: second number.
 *
 * Return: difference between a and b.
 */
int op_sub(int a, int b)
{
	return (a - b);
}

/**
 * op_mul - multiplies two numbers.
 * @a: first number.
 * @b: second number.
 *
 * Return: product of a and b.
 */
int op_mul(int a, int b)
{
	return (a * b);
}

/**
 * op_div - divides the first number by the second number.
 * @a: first number.
 * @b: second number.
 *
 * Return: result of a divided by b.
 *         Exits with code 100 if b is 0.
 */
int op_div(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}
	return (a / b);
}

/**
 * op_mod - calculates the remainder of dividing the first number by
 * the second number.
 * @a: first number.
 * @b: second number.
 *
 * Return: remainder of a divided by b.
 *         Exits with code 100 if b is 0.
 */
int op_mod(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}
	return (a % b);
}

