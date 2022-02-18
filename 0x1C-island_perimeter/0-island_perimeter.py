#!/usr/bin/python3
"""program finds island perimeter"""


def island_perimeter(grid):
    '''the grid is a list of ints, where 0 is water and 1 is land'''
    count = 0
    for a in range(len(grid)):
        for b in range(len(grid[0])):
            if grid[a][b] == 1:
                if a - 1 < 0 or grid[a - 1][b] == 0:
                    count += 1
                if a + 1 == len(grid) or grid[a + 1][b] == 0:
                    count += 1
                if b - 1 < 0 or grid[a][b - 1] == 0:
                    count += 1
                if b + 1 == len(grid[0]) or grid[a][b + 1] == 0:
                    count += 1
    return count
