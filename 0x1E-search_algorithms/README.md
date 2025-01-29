# Search Algorithms

This project implements various search algorithms in C, including linear search, binary search, jump search, interpolation search, and exponential search. Each algorithm is implemented as a separate function, and the time and space complexities are documented.

## Algorithms

1. **Linear Search**: Searches for a value in an array sequentially.
2. **Binary Search**: Efficiently searches for a value in a sorted array using a divide-and-conquer approach.
3. **Jump Search**: Searches for a value by jumping ahead by a fixed number of steps.
4. **Interpolation Search**: Searches for a value by estimating its position based on the value of the elements.
5. **Exponential Search**: Combines binary search with an exponential range to find the range where the element may exist.

## Requirements

- C compiler (GCC)
- Ubuntu 20.04 LTS
- Betty style for coding standards

## Compilation

To compile the code, use the following command:

```bash
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 *.c -o search_algorithms
