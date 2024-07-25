#include "3-calc.h"

/**
 * op_add - Returns the sum of a and b.
 * @a: First operand.
 * @b: Second operand.
 * Return: Sum of a and b.
 */
int op_add(int a, int b)
{
	return (a + b);
}

/**
 * op_sub - Returns the difference of a and b.
 * @a: First operand.
 * @b: Second operand.
 * Return: Difference between a and b.
 */
int op_sub(int a, int b)
{
	return (a - b);
}

/**
 * op_mul - Returns the product of a and b.
 * @a: First operand.
 * @b: Second operand.
 * Return: Product of a and b.
 */
int op_mul(int a, int b)
{
	return (a * b);
}

/**
 * op_div - Returns the result of the division of a by b.
 * @a: Dividend.
 * @b: Divisor.
 * Return: Result of division of a by b.
 */
int op_div(int a, int b)
{
	if (b == 0)
		exit(100); /* Exit with status 100 for division by zero */
	return (a / b);
}

/**
 * op_mod - Returns the remainder of the division of a by b.
 * @a: Dividend.
 * @b: Divisor.
 * Return: Remainder of division of a by b.
 */
int op_mod(int a, int b)
{
	if (b == 0)
		exit(100); /* Exit with status 100 for modulo by zero */
	return (a % b);
}

