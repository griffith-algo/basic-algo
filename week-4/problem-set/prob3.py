"""Prob3 example.

This file belongs to the week 4 divide-and-conquer and memoization examples. It uses F to illustrate the main idea with a small runnable example.
"""

def F(n, memo):
    """Compute the recurrence value using memoization.

    Args:
        n (int): The n input used by this function.
        memo (list): The memoization table used to store earlier results.

    Returns:
        int: The integer result produced by the algorithm.
    """
    if n < 3:
        return 1
    else:
        if memo[n] == -1:
            memo[n] = F(n-1, memo) + F(n-2, memo)
        return memo[n]

n = 10
memo = [-1] * (n + 1)
result = F(n, memo)

print(f"The result of F({n}) is: {result}")