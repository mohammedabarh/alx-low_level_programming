#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_char - Prints a character.
 * @valist: The va_list containing the character to print.
 * @sep: The separator string to print after the character.
 */
void print_char(va_list valist, char *sep)
{
	printf("%c%s", va_arg(valist, int), sep);
}

/**
 * print_int - Prints an integer.
 * @valist: The va_list containing the integer to print.
 * @sep: The separator string to print after the integer.
 */
void print_int(va_list valist, char *sep)
{
	printf("%d%s", va_arg(valist, int), sep);
}

/**
 * print_float - Prints a float.
 * @valist: The va_list containing the float to print.
 * @sep: The separator string to print after the float.
 */
void print_float(va_list valist, char *sep)
{
	printf("%f%s", va_arg(valist, double), sep);
}

/**
 * print_string - Prints a string.
 * @valist: The va_list containing the string to print.
 * @sep: The separator string to print after the string.
 */
void print_string(va_list valist, char *sep)
{
	char *str = va_arg(valist, char *);
	if (str == NULL)
		str = "(nil)";
	printf("%s%s", str, sep);
}

/**
 * print_all - Prints anything based on the format provided.
 * @format: A list of types of arguments passed to the function.
 *
 * Description: c = char, i = int, f = float, s = char * (if null print (nil))
 */
void print_all(const char * const format, ...)
{
	formatter_t formatters[] = {
		{'c', print_char},
		{'i', print_int},
		{'f', print_float},
		{'s', print_string},
		{'\0', NULL}
	};

	va_list valist;
	int i = 0, n = 0;
	char *sep = ", ";

	va_start(valist, format);

	while (format && format[i])
		i++;

	while (format && format[n])
	{
		if (n == (i - 1))
			sep = "";

		for (int j = 0; formatters[j].specifier != '\0'; j++)
		{
			if (format[n] == formatters[j].specifier)
			{
				formatters[j].print_func(valist, sep);
				break;
			}
		}
		n++;
	}
	printf("\n");
	va_end(valist);
}
