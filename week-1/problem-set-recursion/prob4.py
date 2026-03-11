"""Prob4 example.

This file belongs to the week 1 recursion practice solutions. It uses rabbit_count to illustrate the main idea with a small runnable example.
"""

# Fibonacci
def rabbit_count(n):
    """Return the number of rabbit pairs for the classic Fibonacci-style growth model.

    Args:
        n (int): The n input used by this function.

    Returns:
        int: The integer result produced by the algorithm.
    """
    if n == 1 or n == 2:
        return 1
    else:
        return rabbit_count(n-1) + rabbit_count(n-2)

n = 6
print("Rabbit at the year: ", rabbit_count(n)) 