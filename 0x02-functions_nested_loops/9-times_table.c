#include "main.h"

/**
 * times_table - Prints the 9 times table
 *
 * Return: no return
 */
void times_table(void)
{
    int a, b, op;

    for (a = 0; a <= 9; a++)
    {
        _putchar('0');  // Print the initial '0' for the first column
        for (b = 1; b <= 9; b++)
        {
            op = a * b;
            _putchar(',');      // Print the comma separator
            _putchar(' ');      // Print the space after the comma

            // Print the result with correct formatting
            if (op <= 9)
            {
                _putchar(' ');  // Extra space for alignment
                _putchar(op + '0');
            }
            else
            {
                _putchar((op / 10) + '0');
                _putchar((op % 10) + '0');
            }
        }
        _putchar('\n');  // Move to the next line after each row
    }
}

