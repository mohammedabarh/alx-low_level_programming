#include <stdlib.h>

/**
 * argstostr - concatenates all the arguments of the program
 * @ac: the number of arguments
 * @av: an array of pointers to the arguments
 *
 * Return: a pointer to the new string, or NULL if it fails
 */
char *argstostr(int ac, char **av)
{
    char *str;
    int i, j, k, len;

    if (ac == 0 || av == NULL)
        return (NULL);

    /* Calculate the total length of the new string */
    len = 0;
    for (i = 0; i < ac; i++)
    {
        for (j = 0; av[i][j]; j++)
            len++;
        len++; /* For the newline character */
    }

    /* Allocate memory for the new string */
    str = malloc(sizeof(char) * (len + 1));
    if (str == NULL)
        return (NULL);

    /* Copy the arguments into the new string */
    k = 0;
    for (i = 0; i < ac; i++)
    {
        for (j = 0; av[i][j]; j++)
        {
            str[k++] = av[i][j];
        }
        str[k++] = '\n';
    }
    str[k] = '\0';

    return (str);
}
