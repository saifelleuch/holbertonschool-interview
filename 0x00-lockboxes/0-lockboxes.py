#!/usr/bin/python3
"""I have n number of locked boxes
I will try to open them"""


def canUnlockAll(boxes):
    """I have n number of locked boxes
I will try to open them"""

    if len(boxes) == 0:
        return False
    if not isinstance(boxes, list):
        return False

    keys = [0]
    for i, box in enumerate(boxes):
        for key in box:
            if key < (len(boxes)) and key != i:
                keys.append(key)
    keys = list(dict.fromkeys(keys))
    return len(keys) == len(boxes)
