"""Prob9 example.

This file belongs to the week 3 problem-set solutions on sorting, greedy algorithms, and dynamic programming. It uses max_coin_row to illustrate the main idea with a small runnable example.
"""

def max_coin_row(coins):
    """Return the maximum value collectable from non-adjacent coins.

    Args:
        coins (list): The coin values available to the algorithm.

    Returns:
        int: The integer result produced by the algorithm.
    """
    n = len(coins)
    tm = [0] * (n + 1)
    tm[1] = coins[0]
    for i in range(2, n+1):
        tm[i] = max(tm[i-1], coins[i-1] + tm[i-2])
    
    return tm[n]

coins = [5, 1, 2, 10, 6]
print(max_coin_row(coins)) # Output: 15