#!/usr/bin/python3
"""minOperations funct"""


def minOperations(n):
    """Calculates minimum copy all/paste operations"""
    if n < 2:
        return 0

    opp = 0
    total = 1
    copied = 0

    while total < n:
        if n % total == 0:
            copied = total
            opp += 1

        total += copied
        opp += 1

    if total == n:
        return opp

    return 0
