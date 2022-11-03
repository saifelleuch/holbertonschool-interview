#!/usr/bin/python3
"""The N queens puzzle is the
challenge of placing N
non-attacking queens on an N×N chessboard"""

import sys


def nqueens(n: int):
    """ backtracking """
    mtrx = [[0 for i in range(n)] for j in range(n)]
    print(str(mtrx))


if __name__ == "__main__":
    if len(sys.argv) > 2 or len(sys.argv) < 2:
        print("Usage: nqueens N")
        exit(1)

    if not sys.argv[1].isdigit():
        print("N must be a number")
        exit(1)

    if int(sys.argv[1]) < 4:
        print("N must be at least 4")
        exit(1)

    nqueens(int(sys.argv[1]))
