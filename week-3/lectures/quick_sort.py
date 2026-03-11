"""Quick Sort example.

This file belongs to the week 3 lecture examples on graphs, backtracking, and divide-and-conquer algorithms. It uses quick_sort, partition to illustrate the main idea with a small runnable example.
"""

import matplotlib.pyplot as plt
import random

def quick_sort(arr, left, right):
    """Sort the list using quick sort.

    Args:
        arr (list): The list being processed by the algorithm.
        left (object): The left boundary or left-side data used by the algorithm.
        right (object): The right boundary or right-side data used by the algorithm.

    Returns:
        None: This function updates data or prints results and does not return a value.
    """
    if left < right:
        pivot_index = partition(arr, left, right)
        quick_sort(arr, left, pivot_index - 1)
        quick_sort(arr, pivot_index + 1, right)

def partition(arr, left, right):
    """Place the pivot in its final quick-sort position and return its index.

    Args:
        arr (list): The list being processed by the algorithm.
        left (object): The left boundary or left-side data used by the algorithm.
        right (object): The right boundary or right-side data used by the algorithm.

    Returns:
        int: The integer result produced by the algorithm.
    """
    pivot = arr[right]
    i = left - 1
    for j in range(left, right):
        if arr[j] < pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
            # visualize the swap
            plt.bar(range(len(arr)), arr)
            plt.show(block=False)
            plt.pause(0.1)
    arr[i+1], arr[right] = arr[right], arr[i+1]
    # visualize the swap
    plt.bar(range(len(arr)), arr)
    plt.show(block=False)
    plt.pause(0.1)
    return i+1

# generate random data to sort
data = [random.randint(0, 50) for _ in range(15)]
# visualize the initial state
plt.bar(range(len(data)), data)
plt.show(block=False)
plt.pause(1)

# sort the data and visualize each step
quick_sort(data, 0, len(data) - 1)

# visualize the final sorted state
plt.bar(range(len(data)), data)
plt.show()
