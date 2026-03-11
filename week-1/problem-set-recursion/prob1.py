"""Prob1 example.

This file belongs to the week 1 recursion practice solutions. It uses factorial to illustrate the main idea with a small runnable example.
"""

def factorial(n):
    """Return n factorial using recursion.

    Args:
        n (int): The n input used by this function.

    Returns:
        int: The integer result produced by the algorithm.
    """
    if n == 0:
        return 1
    else:
        return n * factorial(n-1)
    
print(factorial(5))