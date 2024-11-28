#!/usr/bin/python3
"""
Module that contains the island_perimeter function
"""


def island_perimeter(grid):
    """
    Returns the perimeter of the island described in grid

    Args:
        grid (list): A list of list of integers representing an island
        where 1 represents land and 0 represents water

    Returns:
        The perimeter of the island defined in grid
    """
    rows = len(grid)
    if rows == 0:
        return 0

    cols = len(grid[0])
    perimeter = 0

    for i in range(rows):
        for j in range(cols):
            if grid[i][j] == 1:
                if i == 0 or grid[i - 1][j] == 0:
                    perimeter += 1
                if i == rows - 1 or grid[i + 1][j] == 0:
                    perimeter += 1
                if j == 0 or grid[i][j - 1] == 0:
                    perimeter += 1
                if j == cols - 1 or grid[i][j + 1] == 0:
                    perimeter += 1

    return perimeter
