"""Bubble Sort example.

This file belongs to the week 5 bubble sort lecture example. It uses bubble
sort to move larger values toward the end of the list one pass at a time.
"""


def bubbleSort(array):
    """Sort the list in ascending order using bubble sort.

    Args:
        array (list): The list being processed by the algorithm.

    Returns:
        None: This function updates data or prints results and does not return a value.
    """
    for pass_number in range(len(array)):
        swapped = False

        for index in range(0, len(array) - pass_number - 1):
            if array[index] > array[index + 1]:
                array[index], array[index + 1] = array[index + 1], array[index]
                swapped = True

        print(array)

        if not swapped:
            break


def main():
    """Run the small demonstration for this teaching example.

    Returns:
        None: This function updates data or prints results and does not return a value.
    """
    data = [6, 5, 3, 1, 8, 7, 2, 4]
    bubbleSort(data)


if __name__ == "__main__":
    main()
