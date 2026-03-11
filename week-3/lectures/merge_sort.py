"""Merge Sort example.

This file belongs to the week 3 lecture examples on graphs, backtracking, and divide-and-conquer algorithms. It uses merge_sort, merge to illustrate the main idea with a small runnable example.
"""

import matplotlib.pyplot as plt
import random

def merge_sort(arr):
    """Sort the list using merge sort.

    Args:
        arr (list): The list being processed by the algorithm.

    Returns:
        list: The list produced by the algorithm.
    """
    if len(arr) > 1:
        mid = len(arr) // 2
        left_arr = arr[:mid]
        right_arr = arr[mid:]
        # recursively sort left and right subarrays
        merge_sort(left_arr)
        merge_sort(right_arr)
        # merge the sorted subarrays
        merge(arr, left_arr, right_arr)

def merge(arr, left_arr, right_arr):
    """Merge two sorted halves into a single sorted result.

    Args:
        arr (list): The list being processed by the algorithm.
        left_arr (list): The sorted left half used during merging.
        right_arr (list): The sorted right half used during merging.

    Returns:
        list: The list produced by the algorithm.
    """
    i = j = k = 0
    while i < len(left_arr) and j < len(right_arr):
        if left_arr[i] < right_arr[j]:
            arr[k] = left_arr[i]
            i += 1
        else:
            arr[k] = right_arr[j]
            j += 1
        k += 1
        # visualize the current state of the array
        plt.bar(range(len(arr)), arr)
        plt.show(block=False)
        plt.pause(0.1)

    while i < len(left_arr):
        arr[k] = left_arr[i]
        i += 1
        k += 1
        # visualize the current state of the array
        plt.bar(range(len(arr)), arr)
        plt.show(block=False)
        plt.pause(0.1)

    while j < len(right_arr):
        arr[k] = right_arr[j]
        j += 1
        k += 1
        # visualize the current state of the array
        plt.bar(range(len(arr)), arr)
        plt.show(block=False)
        plt.pause(0.1)

# generate random data to sort
data = [random.randint(0, 50) for _ in range(15)]
# visualize the initial state
plt.bar(range(len(data)), data)
plt.show(block=False)
plt.pause(1)

# sort the data and visualize each step
merge_sort(data)

# visualize the final sorted state
plt.bar(range(len(data)), data)
plt.show()
