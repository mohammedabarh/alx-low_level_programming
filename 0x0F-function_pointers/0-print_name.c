#include "function_pointers.h"
#include <stdio.h>

/**
 * print_name - Prints a name using a provided function pointer.
 * @name: The name to print.
 * @f: A pointer to the function that will print the name.
 *
 * Return: None.
 */
void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
		return;

	/* Call the function with name as its argument */
	f(name);
}

