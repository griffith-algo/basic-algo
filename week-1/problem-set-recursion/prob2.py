"""Prob2 example.

This file belongs to the week 1 recursion practice solutions. It uses find_max to illustrate the main idea with a small runnable example.
"""

def find_max(numbers):
    """Return the largest value in the list using recursion.

    Args:
        numbers (list): The list of numbers used in the example.

    Returns:
        int: The integer result produced by the algorithm.
    """
    if len(numbers) == 1:
        return numbers[0]
    else:
        max_val = find_max(numbers[1:])
        return numbers[0] if numbers[0] > max_val else max_val

numbers = [5, 10, 3, 8, 1]
print(find_max(numbers))