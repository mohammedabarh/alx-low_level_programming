#include "main.h"

/**
 * main - Prints _putchar followed by a newline
 *
 * Return: Always 0.
 */
int main(void)
{
    char *str = "_putchar";
    int i = 0;

    while (str[i])
    {
        _putchar(str[i]);
        i++;
    }

    _putchar('\n');
    return (0);
}
