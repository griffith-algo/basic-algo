"""Quick Sort example.

This file belongs to the week 5 quick sort lecture example. It uses partition, quickSort to illustrate the main idea with a small runnable example.
"""

# Quick sort in Python

# function to find the partition position
def partition(array, low, high):

    # choose the rightmost element as pivot
    """Place the pivot in its final quick-sort position and return its index.

    Args:
        array (list): The list being processed by the algorithm.
        low (int): The low input used by this function.
        high (int): The high input used by this function.

    Returns:
        int: The integer result produced by the algorithm.
    """
    pivot = array[high]

    # pointer for greater element
    i = low - 1

    # traverse through all elements
    # compare each element with pivot
    for j in range(low, high):
        if array[j] <= pivot:
            # if element smaller than pivot is found
            # swap it with the greater element pointed by i
            i = i + 1

            # swapping element at i with element at j
            (array[i], array[j]) = (array[j], array[i])

    # swap the pivot element with the greater element specified by i
    (array[i + 1], array[high]) = (array[high], array[i + 1])

    # return the position from where partition is done
    return i + 1

# function to perform quicksort
def quickSort(array, low, high):
    """Sort the list in ascending order using quick sort.

    Args:
        array (list): The list being processed by the algorithm.
        low (int): The low input used by this function.
        high (int): The high input used by this function.

    Returns:
        None: This function updates data or prints results and does not return a value.
    """
    if low < high:

        # find pivot element such that
        # element smaller than pivot are on the left
        # element greater than pivot are on the right
        pi = partition(array, low, high)

        # recursive call on the left of pivot
        quickSort(array, low, pi - 1)

        # recursive call on the right of pivot
        quickSort(array, pi + 1, high)


data = [8, 7, 2, 1, 0, 9, 6]
print("Unsorted Array")
print(data)

size = len(data)

quickSort(data, 0, size - 1)

print('Sorted Array in Ascending Order:')
print(data)