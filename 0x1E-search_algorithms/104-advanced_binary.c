#include "search_algos.h"

/**
 * recursive_binary - Recursively searches for a value in a sorted array
 * @array: Pointer to first element of array to search in
 * @left: Left index of the subarray
 * @right: Right index of the subarray
 * @value: Value to search for
 *
 * Return: Index where value is located, or -1 if not found
 */
int recursive_binary(int *array, size_t left, size_t right, int value)
{
    size_t i, mid;

    if (right < left)
        return (-1);

    /* Print the current subarray being searched */
    printf("Searching in array: ");
    for (i = left; i <= right; i++)
    {
        printf("%d", array[i]);
        if (i < right)
            printf(", ");
    }
    printf("\n");

    mid = left + (right - left) / 2;

    if (array[mid] == value)
    {
        if (mid == left || array[mid - 1] != value)
            return (mid);
        return (recursive_binary(array, left, mid, value));
    }
    if (array[mid] > value)
        return (recursive_binary(array, left, mid, value));
    return (recursive_binary(array, mid + 1, right, value));
}

/**
 * advanced_binary - Searches for a value in a sorted array using binary search
 * @array: Pointer to first element of array to search in
 * @size: Number of elements in array
 * @value: Value to search for
 *
 * Return: Index where value is located, or -1 if not found
 */
int advanced_binary(int *array, size_t size, int value)
{
    if (!array || size == 0)
        return (-1);

    return (recursive_binary(array, 0, size - 1, value));
}
