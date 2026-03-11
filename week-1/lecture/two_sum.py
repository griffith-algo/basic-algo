"""Two Sum example.

This file belongs to the introductory lecture examples on recursion, searching, and simple sorting. It uses two_sum to illustrate the main idea with a small runnable example.
"""

def two_sum(nums, target):
    """Return the indices of two numbers whose sum matches the target.

    Args:
        nums (list): The list of numbers searched by the algorithm.
        target (object): The target input used by this function.

    Returns:
        list: The list produced by the algorithm.
    """
    seen = {}
    for i, num in enumerate(nums):
        complement = target - num
        if complement in seen:
            return [seen[complement], i]
        seen[num] = i
    return []

print(two_sum([2, 7, 11, 15], 9))