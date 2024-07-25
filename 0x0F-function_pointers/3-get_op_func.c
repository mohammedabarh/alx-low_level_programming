#include "3-calc.h"

/**
 * get_op_func - Selects the correct function to perform the operation.
 * @s: The operator as a string.
 *
 * Return: A pointer to the function that performs the requested operation,
 *         or NULL if the operator is not recognized.
 */
int (*get_op_func(char *s))(int, int)
{
	/* Array of operators and corresponding functions */
	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL}
	};

	int i = 0;

	/* Iterate through the array of operators */
	for (; ops[i].op != NULL; i++)
	{
		if (*s == *(ops[i].op) && *(s + 1) == '\0')
		{
			return (ops[i].f);
		}
	}

	/* Return NULL if no matching operator is found */
	return (NULL);
}

