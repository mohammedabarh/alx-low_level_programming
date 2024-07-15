#include <stdlib.h>
#include <stdio.h>

/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 *           which contains a copy of the string given as a parameter.
 * @str: the string to duplicate
 *
 * Return: a pointer to the duplicated string, or NULL if insufficient memory
 *         was available or if str is NULL
 */
char *_strdup(char *str)
{
	char *dup_str;
	int i, len = 0;

	if (str == NULL)
		return (NULL);

	/* Calculate the length of the input string */
	while (str[len] != '\0')
		len++;

	/* Allocate memory for the duplicated string */
	dup_str = (char *)malloc(sizeof(char) * (len + 1));
	if (dup_str == NULL)
		return (NULL);

	/* Copy the string */
	for (i = 0; i < len; i++)
		dup_str[i] = str[i];
	dup_str[len] = '\0';

	return (dup_str);
}
