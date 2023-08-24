#!/usr/bin/python3
'''perimeter of the island described in grid'''


def island_perimeter(grid):
    """_summary_

    Args:
        grid (_type_): _description_

    Returns:
        _type_: _description_
    """    
    final = 0
    for y, row in enumerate(grid):
        for x, cell in enumerate(row):
            if cell == 1:
                if y == 0 or grid[y - 1][x] == 0:
                    final += 1
                if y == len(grid) - 1 or grid[y + 1][x] == 0:
                    final += 1
                if x == 0 or grid[y][x - 1] == 0:
                    final += 1
                if x == len(row) - 1 or grid[y][x + 1] == 0:
                    final += 1
    return final
