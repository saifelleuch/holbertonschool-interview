#!/usr/bin/python3
""" Rain """


def rain(walls):
    """ Rain """
    if walls is None:
        return 0
    indexLeft = 0
    indexRight = len(walls) - 1
    leftMax = 0
    rightMax = 0
    rainwater = 0
    while (indexLeft <= indexRight):
        leftMax = max(leftMax, walls[indexLeft])
        rightMax = max(rightMax, walls[indexRight])
        if leftMax < rightMax:
            rainwater += leftMax - walls[indexLeft]
            indexLeft += 1
        else:
            rainwater += rightMax - walls[indexRight]
            indexRight -= 1
    return rainwater
