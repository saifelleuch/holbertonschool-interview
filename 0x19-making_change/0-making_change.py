#!/usr/bin/python3
""" 0x19. Making Change """


def makeChange(coins, total):
    """ Given a pile of coins of different values,
        determine the fewest number
        of coins needed to meet a given amount total.
    """
    if total < 1:
        return 0
    coins.sort()
    coins.reverse()
    fewest_number_coins = 0
    for coin in coins:
        if total <= 0:
            break
        buff = total // coin
        fewest_number_coins += buff
        total -= (buff * coin)
    if total != 0:
        return -1
    return fewest_number_coins
