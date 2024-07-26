#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/* Helper functions for printing different types */
void print_char(va_list valist);
void print_int(va_list valist);
void print_float(va_list valist);
void print_string(va_list valist);

/**
 * print_all - Prints various types of arguments based on the format string.
 * @format: A string specifying the types of the arguments to be printed.
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
			print_char(valist);
			sep = ", ";
			break;
		case 'i':
			print_int(valist);
			sep = ", ";
			break;
		case 'f':
			print_float(valist);
			sep = ", ";
			break;
		case 's':
			print_string(valist);
			sep = ", ";
			break;
		default:
			sep = "";
			break;
		}

		i++;
	}

	printf("\n");
	va_end(valist);
}

/**
 * print_char - Prints a character.
 * @valist: The variable argument list.
 */
void print_char(va_list valist)
{
	printf("%c", va_arg(valist, int));
}

/**
 * print_int - Prints an integer.
 * @valist: The variable argument list.
 */
void print_int(va_list valist)
{
	printf("%d", va_arg(valist, int));
}

/**
 * print_float - Prints a float.
 * @valist: The variable argument list.
 */
void print_float(va_list valist)
{
	printf("%f", va_arg(valist, double));
}

/**
 * print_string - Prints a string. If the string is NULL, prints (nil).
 * @valist: The variable argument list.
 */
void print_string(va_list valist)
{
	char *str = va_arg(valist, char *);

	if (str == NULL)
		str = "(nil)";
	printf("%s", str);
}

