#include "main.h"
#include <stdlib.h>

/**
 * create_array - Create an array of a specified size and initialize it with a character.
 * @size: The size of the array to create.
 * @c: The character to initialize the array with.
 *
 * Description: Create an array of size 'size' and initialize each element with the character 'c'.
 * Return: A pointer to the created array, or NULL if the allocation fails or the size is 0.
 */
char *create_array(unsigned int size, char c)
{
    if (size == 0) {
        return NULL;
    }

    char *arr = (char *)malloc(size * sizeof(char));
    if (arr == NULL) {
        return NULL;
    }

    for (unsigned int i = 0; i < size; i++) {
        arr[i] = c;
    }

    return arr;
}
