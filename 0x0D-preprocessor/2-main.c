#include <stdio.h>

/**
 * main - prints the name of the file it was compiled from
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	const char *filename = __FILE__;

	printf("%s\n", filename);
	return (0);
}

