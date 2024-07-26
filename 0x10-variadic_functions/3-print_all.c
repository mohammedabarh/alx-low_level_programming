#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_char - Prints a character.
 * @val: The character to print.
 */
void print_char(int val)
{
	printf("%c", val);
}

/**
 * print_int - Prints an integer.
 * @val: The integer to print.
 */
void print_int(int val)
{
	printf("%d", val);
}

/**
 * print_float - Prints a float.
 * @val: The float to print.
 */
void print_float(double val)
{
	printf("%f", val);
}

/**
 * print_string - Prints a string.
 * @val: The string to print.
 */
void print_string(char *val)
{
	if (val == NULL)
		printf("(nil)");
	else
		printf("%s", val);
}

/**
 * print_all - Prints anything based on the format specifiers.
 * @format: A string representing the format of the arguments.
 */
void print_all(const char * const format, ...)
{
	va_list valist;
	unsigned int i = 0;
	char *sep = "";

	va_start(valist, format);

	while (format && format[i])
	{
		if (i > 0)
			printf("%s", sep);

		switch (format[i])
		{
			case 'c':
				print_char(va_arg(valist, int));
				sep = ", ";
				break;
			case 'i':
				print_int(va_arg(valist, int));
				sep = ", ";
				break;
			case 'f':
				print_float(va_arg(valist, double));
				sep = ", ";
				break;
			case 's':
				print_string(va_arg(valist, char *));
				sep = ", ";
				break;
			default:
				i++;
				continue;
		}
		i++;
	}

	printf("\n");
	va_end(valist);
}

