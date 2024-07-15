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
	
	if (str == NULL)
		return (NULL);
	
	while (str[len] != '\0')
		len++;
	dup = malloc(sizeof(char) * (len + 1));
	
	if (dup == NULL)
		return (NULL);
	
	for (unsigned int i = 0; i <= len; i++)
		dup[i] = str[i];
	
	return (dup);
}
