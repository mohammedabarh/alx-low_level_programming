#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * sum_them_all - Returns the sum of all its parameters.
 * @n: The number of parameters passed to the function.
 *
 * Return: If n == 0 - 0.
 *         Otherwise - the sum of all parameters.
 */
int sum_them_all(const unsigned int n, ...)
{
    va_list valist;
    int *arr;
    unsigned int i;
    int sum = 0;

    if (n == 0)
        return (0);

    /* Allocate memory for an array to store the parameters */
    arr = malloc(n * sizeof(int));
    if (arr == NULL)
        return (0);  /* Handle memory allocation failure */

    va_start(valist, n);

    /* Store the parameters in the array */
    for (i = 0; i < n; i++)
    {
        arr[i] = va_arg(valist, int);
    }

    va_end(valist);

    /* Calculate the sum from the stored parameters */
    for (i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    free(arr);  /* Free the allocated memory */

    return (sum);
}
