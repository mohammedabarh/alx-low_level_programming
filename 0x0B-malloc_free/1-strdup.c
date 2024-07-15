#include <stdio.h>
#include <stdlib.h>
#include "main.h"


/**
 * _strdup - Allocates a new memory area and copies the content of the
 * input string to it.
 *
 * @str: The input string to be duplicated.
 *
 * Return: A pointer to the duplicated string, or NULL if it fails.
 */
char *_strdup(char *str)
{
    char *dup;
    unsigned int len = 0;

    /* Check if the input string is NULL */
    if (str == NULL)
        return (NULL);

    /* Calculate the length of the input string */
    while (str[len] != '\0')
        len++;

    /* Allocate memory for the duplicate string */
    dup = malloc(sizeof(char) * (len + 1));

    /* Check if the memory allocation was successful */
    if (dup == NULL)
        return (NULL);

    /* Copy the content of the input string to the new memory area */
    for (unsigned int i = 0; i <= len; i++)
        dup[i] = str[i];

    return (dup);
}
