#!/usr/bin/python3
"""contains function to display Pascal's Triangle"""


def pascal_triangle(n):
    """returns list of lists representing Pascal's Triangle"""
    output = []
    for b in range(n):
        row = [1]
        for a in range(b):
            if a + 1 == b:
                res = 1
            else:
                res = output[b - 1][a] + output[b - 1][a + 1]
            row.append(res)
        output.append(row)
    return output
