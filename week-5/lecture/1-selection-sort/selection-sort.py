"""Selection Sort example.

This file belongs to the week 5 selection sort lecture example. It uses selectionSort to illustrate the main idea with a small runnable example.
"""

# Selection sort in Python

def selectionSort(array, size):
   
    """Sort the list in ascending order using selection sort.

    Args:
        array (list): The list being processed by the algorithm.
        size (object): The size input used by this function.

    Returns:
        None: This function updates data or prints results and does not return a value.
    """
    for step in range(size):
        min_idx = step

        for i in range(step + 1, size):
         
            # to sort in descending order, change > to < in this line
            # select the minimum element in each loop
            if array[i] < array[min_idx]:
                min_idx = i
        print(array)
         
        # put min at the correct position
        (array[step], array[min_idx]) = (array[min_idx], array[step])


data = [-2, 45, 0, 11, -9, 3]
size = len(data)
selectionSort(data, size)