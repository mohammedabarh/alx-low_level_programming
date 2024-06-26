#include <stdio.h>

/**
 * main - Prints the sum of the even-valued Fibonacci numbers
 *
 * Return: Always 0
 */
int main(void)
{
	long int a = 1, b = 2, c, sum = 2;

	while (b <= 4000000)
	{
		c = a + b;
		a = b;
		b = c;

		if (b % 2 == 0)
			sum += b;
	}

	printf("%ld\n", sum);

	return (0);
}
