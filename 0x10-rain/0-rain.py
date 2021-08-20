#!/usr/bin/python3
"""rain method"""


def rain(walls):
    """valculates how much water"""
    total = 0
    leftwall = -1
    rightwall = -1

    for i in range(len(walls)):
        if leftwall == -1 and walls[i] > 0:
            leftwall = i
        elif leftwall != -1 and walls[i] >= walls[leftwall]:
            total += (i - (leftwall + 1)) * walls[leftwall]
            leftwall = i

    for i in range(len(walls) - 1, -1, -1):
        if rightwall == -1 and walls[i] > 0:
            rightwall = i
        elif rightwall != -1 and walls[i] >= walls[rightwall]:
            total += (rightwall - (i + 1)) * walls[rightwall]
            rightwall = i
        if rightwall == leftwall:
            break

    return total
