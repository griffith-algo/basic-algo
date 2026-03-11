"""Prob4 example.

This file belongs to the week 3 problem-set solutions on sorting, greedy
algorithms, and dynamic programming. It demonstrates bubble sort and the common
early-exit optimisation.
"""


def bubble_sort(array):
    """Sort the list using bubble sort.

    Args:
        array (list): The list being processed by the algorithm.

    Returns:
        list: The list produced by the algorithm.
    """
    n = len(array)

    for i in range(n):
        swapped = False

        for j in range(0, n - i - 1):
            if array[j] > array[j + 1]:
                array[j], array[j + 1] = array[j + 1], array[j]
                swapped = True

        if not swapped:
            print("No swaps were needed on this pass, so the list is already sorted.")
            break

    return array


def main():
    """Run the small demonstration for this teaching example.

    Returns:
        None: This function updates data or prints results and does not return a value.
    """
    my_list = [4, 2, 8, 3, 1, 9, 6, 5, 7]
    print("Original list:", my_list)
    print("Sorted list:", bubble_sort(my_list))


if __name__ == "__main__":
    main()
