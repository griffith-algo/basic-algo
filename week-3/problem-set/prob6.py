"""Prob6 example.

This file belongs to the week 3 problem-set solutions on sorting, greedy
algorithms, and dynamic programming. It counts how many ways a sum can be made
with unlimited copies of the given coins.
"""


def count_dynamic_programming(coins, n, total):
    """Count the number of ways to make the target sum using dynamic programming.

    Args:
        coins (list): The coin values available to the algorithm.
        n (int): The n input used by this function.
        total (int): The total input used by this function.

    Returns:
        int: The integer result produced by the algorithm.
    """
    table = [[0] * (total + 1) for _ in range(n + 1)]

    # There is always exactly one way to make a total of 0: choose no coins.
    for row in range(n + 1):
        table[row][0] = 1

    for coin_index in range(1, n + 1):
        coin = coins[coin_index - 1]
        for amount in range(1, total + 1):
            ways_without_coin = table[coin_index - 1][amount]
            ways_with_coin = table[coin_index][amount - coin] if coin <= amount else 0
            table[coin_index][amount] = ways_without_coin + ways_with_coin

    return table[n][total]


def main():
    """Run the small demonstration for this teaching example.

    Returns:
        None: This function updates data or prints results and does not return a value.
    """
    print(count_dynamic_programming([1, 2, 3], 3, 4))


if __name__ == "__main__":
    main()
