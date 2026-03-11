"""Insertion Sort example.

This file belongs to the week 5 insertion sort lecture example. It uses insertionSort to illustrate the main idea with a small runnable example.
"""

# Insertion sort in Python


def insertionSort(array):

    """Sort the list in ascending order using insertion sort.

    Args:
        array (list): The list being processed by the algorithm.

    Returns:
        None: This function updates data or prints results and does not return a value.
    """
    for step in range(1, len(array)):
        key = array[step]
        j = step - 1
        
        # Compare key with each element on the left of it until an element smaller than it is found
        # For descending order, change key<array[j] to key>array[j].        
        while j >= 0 and key < array[j]:
            array[j + 1] = array[j]
            j = j - 1
        
        # Place key at after the element just smaller than it.
        array[j + 1] = key
        print(array)


data = [6, 5, 3, 1, 8, 7, 2, 4]
insertionSort(data)