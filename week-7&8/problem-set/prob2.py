"""Prob2 example.

This file belongs to the week 7 and 8 tree and hashing practice solutions. It uses two_way_comparison_binary_search to illustrate the main idea with a small runnable example.
"""

def two_way_comparison_binary_search(arr, target):
    """Search a sorted list using one equality test and one ordering test per loop.

    Args:
        arr (list): The list being processed by the algorithm.
        target (object): The target input used by this function.

    Returns:
        int: The integer result produced by the algorithm.
    """
    left, right = 0, len(arr) - 1

    while left <= right:
        mid = (left + right) // 2

        # Check if the middle element is equal to the target value
        if arr[mid] == target:
            return mid

        # Check if the middle element is less than or equal to the target value
        if arr[mid] <= target:
            left = mid + 1
        else:
            right = mid - 1

    # If the loop finishes without finding the target, return -1
    return -1


# Test the two_way_comparison_binary_search function
arr = [3, 14, 27, 31, 39, 42, 55, 70, 74, 81, 85, 93, 98]
target = 3
result = two_way_comparison_binary_search(arr, target)

if result != -1:
    print(f"Element {target} found at index {result}.")
else:
    print(f"Element {target} not found in the array.")
