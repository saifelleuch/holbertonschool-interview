#!/usr/bin/python3
"""utf8 validation"""


def validUTF8(data):
    """utf8 validation"""
    nbr_bytes = 0
    first_num = 1 << 7
    last_num = 1 << 6
    for number in data:
        num = 1 << 7
        if nbr_bytes == 0:
            while num & number:
                nbr_bytes += 1
                num = num >> 1
            if nbr_bytes == 0:
                continue
            if nbr_bytes == 1 or nbr_bytes > 4:
                return False
        else:
            if not (number & first_num and not (number & last_num)):
                return False
        nbr_bytes -= 1
    return nbr_bytes == 0
