#!/usr/bin/python3
"""0. Minimum Operations"""


from unittest import result


def minOperations(n):
    """method that calculates the fewest number
    of operations needed to result in exactly n
    H characters in the file."""
    if type(n) is not int or n <= 1:
        return 0
    i = 0
    result = 2
    while n > 1:
        if n % result == 0:
            i = i + result
            n = n / result
        else:
            result = result + 1
    return i
