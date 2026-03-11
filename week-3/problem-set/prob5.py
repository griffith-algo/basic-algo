"""Prob5 example.

This file belongs to the week 3 problem-set solutions on sorting, greedy algorithms, and dynamic programming. It uses find_largest_position to illustrate the main idea with a small runnable example.
"""

def find_largest_position(arr, left, right):
    """Return the index of the largest value using divide and conquer.

    Args:
        arr (list): The list being processed by the algorithm.
        left (object): The left boundary or left-side data used by the algorithm.
        right (object): The right boundary or right-side data used by the algorithm.

    Returns:
        int: The integer result produced by the algorithm.
    """
    if left == right:
        return left
    else:
        mid = (left + right) // 2
        left_max_position = find_largest_position(arr, left, mid)
        right_max_position = find_largest_position(arr, mid + 1, right)
        if arr[left_max_position] >= arr[right_max_position]:
            return left_max_position
        else:
            return right_max_position

arr = [3, 5, 4, 6, 2]
largest_position = find_largest_position(arr, 0, len(arr)-1)
print("The largest element in the array is at position", largest_position)
