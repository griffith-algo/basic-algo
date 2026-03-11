"""Prob7 example.

This file belongs to the week 3 problem-set solutions on sorting, greedy algorithms, and dynamic programming. It uses greedy_change_with_denominations to illustrate the main idea with a small runnable example.
"""

def greedy_change_with_denominations(n, denominations):
    """Choose coins greedily from largest denomination to smallest.

    Args:
        n (int): The n input used by this function.
        denominations (object): The denominations input used by this function.

    Returns:
        dict: The dictionary produced by the algorithm.
    """
    num_coins = 0
    denominations_used = {}
    for denomination in denominations:
        while n >= denomination:
            n -= denomination
            num_coins += 1
            if denomination not in denominations_used:
                denominations_used[denomination] = 1
            else:
                denominations_used[denomination] += 1
    return denominations_used

denominations = [9, 3, 2]
n = 11
denominations_used = greedy_change_with_denominations(n, denominations)
print(denominations_used)
