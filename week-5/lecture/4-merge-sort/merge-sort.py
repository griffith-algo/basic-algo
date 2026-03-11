"""Merge Sort example.

This file belongs to the week 5 merge sort lecture example. It recursively
splits the list and then merges the sorted halves.
"""


def merge(left_half, right_half):
    """Merge two sorted lists into one sorted list.

    Args:
        left_half (object): The left_half input used by this function.
        right_half (object): The right_half input used by this function.

    Returns:
        list: The list produced by the algorithm.
    """
    merged = []
    left_index = 0
    right_index = 0

    while left_index < len(left_half) and right_index < len(right_half):
        if left_half[left_index] <= right_half[right_index]:
            merged.append(left_half[left_index])
            left_index += 1
        else:
            merged.append(right_half[right_index])
            right_index += 1

    merged.extend(left_half[left_index:])
    merged.extend(right_half[right_index:])
    return merged


def mergeSort(array):
    """Sort the list in ascending order using merge sort.

    Args:
        array (list): The list being processed by the algorithm.

    Returns:
        list: The list produced by the algorithm.
    """
    if len(array) <= 1:
        return array

    middle = len(array) // 2
    left_half = mergeSort(array[:middle])
    right_half = mergeSort(array[middle:])
    merged = merge(left_half, right_half)
    print(merged)
    return merged


def main():
    """Run the small demonstration for this teaching example.

    Returns:
        None: This function updates data or prints results and does not return a value.
    """
    data = [6, 5, 3, 1, 8, 7, 2, 4]
    print("Sorted array:", mergeSort(data))


if __name__ == "__main__":
    main()
