"""Prob5 example.

This file belongs to the worked week 1 problem-set solutions. It uses min_distance to illustrate the main idea with a small runnable example.
"""

def min_distance(arr):
    """Return the smallest distance between any two values in the list.

    Args:
        arr (list): The list being processed by the algorithm.

    Returns:
        int: The integer result produced by the algorithm.
    """
    arr.sort()
    dmin = float('inf')
    for i in range(1, len(arr)):
        d = abs(arr[i] - arr[i-1])
        if d < dmin:
            dmin = d
    return dmin

arr = [2, 4, 8, 3, 10]
print(min_distance(arr))