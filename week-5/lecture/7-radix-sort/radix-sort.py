"""Radix Sort example.

This file belongs to the week 5 radix sort lecture example. It uses countingSort, radixSort to illustrate the main idea with a small runnable example.
"""

# Radix sort in Python


# Using counting sort to sort the elements in the basis of significant places
def countingSort(array, place):
    """Sort the values by one digit position as part of radix sort.

    Args:
        array (list): The list being processed by the algorithm.
        place (int): The place input used by this function.

    Returns:
        None: This function updates data or prints results and does not return a value.
    """
    size = len(array)
    output = [0] * size
    count = [0] * 10

    # Calculate count of elements
    for i in range(0, size):
        index = array[i] // place
        count[index % 10] += 1

    # Calculate cumulative count
    for i in range(1, 10):
        count[i] += count[i - 1]

    # Place the elements in sorted order
    i = size - 1
    while i >= 0:
        index = array[i] // place
        output[count[index % 10] - 1] = array[i]
        count[index % 10] -= 1
        i -= 1

    for i in range(0, size):
        array[i] = output[i]


# Main function to implement radix sort
def radixSort(array):
    # Get maximum element
    """Sort non-negative integers using radix sort.

    Args:
        array (list): The list being processed by the algorithm.

    Returns:
        None: This function updates data or prints results and does not return a value.
    """
    max_element = max(array)

    # Apply counting sort to sort elements based on place value.
    place = 1
    while max_element // place > 0:
        countingSort(array, place)
        place *= 10


data = [121, 432, 564, 23, 1, 45, 788]
radixSort(data)
print(data)