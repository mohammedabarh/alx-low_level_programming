#include <stdio.h>
#include <stdlib.h>

/**
 * print_opcodes - prints the opcodes of a given memory region.
 * @start: pointer to the start of the memory region.
 * @bytes: number of bytes to print.
 */
void print_opcodes(unsigned char *start, int bytes)
{
	int i;

	for (i = 0; i < bytes; i++)
	{
		if (i > 0)
			printf(" ");
		printf("%02x", start[i]);
	}
	printf("\n");
}

/**
 * main - prints the opcodes of the main function.
 * @argc: number of command-line arguments.
 * @argv: array of command-line arguments.
 *
 * Return: 0 on success, exits with status 1 or 2 on error.
 */
int main(int argc, char *argv[])
{
	int num_bytes;
	unsigned char *main_ptr;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}

	num_bytes = atoi(argv[1]);
	if (num_bytes < 0)
	{
		printf("Error\n");
		exit(2);
	}

	main_ptr = (unsigned char *)main;
	print_opcodes(main_ptr, num_bytes);

	return (0);
}

