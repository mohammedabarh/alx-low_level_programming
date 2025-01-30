#include "search_algos.h"
#include <stdio.h>

int interpolation_search(int *array, size_t size, int value)
{
    int low = 0, high = size - 1, pos;

    while (low <= high && value >= array[low] && value <= array[high])
    {
        pos = low + ((double)(high - low) / (array[high] - array[low]) * (value - array[low]));

        if (pos >= size)
        {
            printf("Value checked array[%d] is out of range\n", pos);
            return -1;
        }

        printf("Value checked array[%d] = [%d]\n", pos, array[pos]);

        if (array[pos] == value)
            return pos;
        if (array[pos] < value)
            low = pos + 1;
        else
            high = pos - 1;
    }
    return -1;
}
