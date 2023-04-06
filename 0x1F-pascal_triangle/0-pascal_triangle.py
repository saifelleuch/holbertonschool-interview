#!/usr/bin/python3
""" 0. Pascal's Triangle """


def pascal_triangle(n):
    """ A function that returns a list of lists of
    integers representing the Pascal’s triangle of n
    """
    PT_List = []
    if n <= 0:
        return PT_List

    PT_List = [[1]]
    if n == 1:
        return PT_List

    for row in range(1, n):
        left = -1
        right = 0
        Int_List = []
        for column in range(row+1):
            integer = 0
            if left > -1:
                integer += PT_List[row - 1][left]
            if right < row:
                integer += PT_List[row - 1][right]
            left += 1
            right += 1
            Int_List.append(integer)
        PT_List.append(Int_List)
    return PT_List
