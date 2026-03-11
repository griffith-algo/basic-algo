"""Prob2 example.

This file belongs to the week 4 divide-and-conquer and memoization examples. It uses find_min_max to illustrate the main idea with a small runnable example.
"""

def find_min_max(arr, low, high):
    """Return the minimum and maximum values using divide and conquer.

    Args:
        arr (list): The list being processed by the algorithm.
        low (int): The low input used by this function.
        high (int): The high input used by this function.

    Returns:
        tuple: The tuple of values produced by the algorithm.
    """
    if low == high:
        return (arr[low], arr[low])
    elif high == low + 1:
        return (min(arr[low], arr[high]), max(arr[low], arr[high]))
    else:
        mid = (low + high) // 2
        (min1, max1) = find_min_max(arr, low, mid)
        (min2, max2) = find_min_max(arr, mid+1, high)
        return (min(min1, min2), max(max1, max2))

# Example usage
arr = [3, 7, 1, 8, 2, 5]
n = len(arr)
(minimum, maximum) = find_min_max(arr, 0, n-1)

print("Array:", arr)
print("Minimum:", minimum)
print("Maximum:", maximum)