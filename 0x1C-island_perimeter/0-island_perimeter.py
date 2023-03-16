#!/usr/bin/python3
""" 0. Island Perimeter """


def island_perimeter(grid):
    """  returns the perimeter of
    the island described in grid """

    if not grid or not grid[0]:
        return 0

    rows = len(grid)
    columns = len(grid[0])
    land = 1
    perimeter = 0

    for row in range(rows):
        for col in range(columns):
            if grid[row][col] is land:
                perimeter += 4
                if row > 0 and grid[row - 1][col] is land:
                    perimeter -= 2
                if col > 0 and grid[row][col - 1] is land:
                    perimeter -= 2
    return perimeter
