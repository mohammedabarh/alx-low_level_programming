#include <stdio.h>

/**
 * main - Prints the sum of the Fibonacci numbers
 *
 * Return: Always 0
 */
int main(void)
{
	long int a = 1, b = 2, c, sum = 3;
	int i;

	printf("%ld, %ld, ", a, b);

	for (i = 0; i < 47; i++)
	{
		c = a + b;
		printf("%ld", c);
		sum += c;
		a = b;
		b = c;

		if (i < 46)
			printf(", ");
	}

	printf("\n");
	printf("Sum: %ld\n", sum);

	return (0);
}
