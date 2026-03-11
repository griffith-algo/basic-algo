"""Prob8 example.

This file belongs to the worked week 1 problem-set solutions. It shows two
different deletion ideas: constant-time deletion in an unsorted list, and lazy
deletion inside a sorted list.
"""


def delete_element(arr, i):
    """Delete one list element in constant time by swapping it with the last value.

    Args:
        arr (list): The list being processed by the algorithm.
        i (int): The i input used by this function.

    Returns:
        list: The list produced by the algorithm.
    """
    if not 0 <= i < len(arr):
        raise IndexError("Index out of range")

    # We lose the original order, but the removal itself is O(1).
    arr[i], arr[-1] = arr[-1], arr[i]
    arr.pop()
    return arr


class SortedArray:
    """Sorted array that marks deleted positions instead of removing them."""

    def __init__(self, arr):
        """Store the sorted values and a matching list of deletion markers.

        Args:
            arr (list): The list being processed by the algorithm.

        Returns:
            None: This function updates data or prints results and does not return a value.
        """
        self.arr = list(arr)
        self.deleted = [False] * len(arr)

    def _nearest_active_index(self, mid, left, right):
        """Return the closest undeleted index around the midpoint.

        Args:
            mid (int): The mid input used by this function.
            left (object): The left boundary or left-side data used by the algorithm.
            right (object): The right boundary or right-side data used by the algorithm.

        Returns:
            int: The integer result produced by the algorithm.
        """
        offset = 0
        while mid - offset >= left or mid + offset <= right:
            left_candidate = mid - offset
            right_candidate = mid + offset

            if left_candidate >= left and not self.deleted[left_candidate]:
                return left_candidate
            if right_candidate <= right and not self.deleted[right_candidate]:
                return right_candidate

            offset += 1

        return None

    def delete(self, i):
        """Mark the value at index i as deleted.

        Args:
            i (int): The i input used by this function.

        Returns:
            None: This function updates data or prints results and does not return a value.
        """
        if not 0 <= i < len(self.arr):
            raise IndexError("Index out of range")
        self.deleted[i] = True

    def search(self, x):
        """Search for x while skipping positions that were lazily deleted.

        Args:
            x (int): The x input used by this function.

        Returns:
            int: The integer result produced by the algorithm.
        """
        left = 0
        right = len(self.arr) - 1

        while left <= right:
            mid = (left + right) // 2
            active_mid = self._nearest_active_index(mid, left, right)

            if active_mid is None:
                return -1

            if self.arr[active_mid] < x:
                left = active_mid + 1
            elif self.arr[active_mid] > x:
                right = active_mid - 1
            else:
                return active_mid

        return -1

    def __len__(self):
        """Return the number of values that have not been deleted.

        Returns:
            int: The integer result produced by the algorithm.
        """
        return sum(1 for flag in self.deleted if not flag)

    def __getitem__(self, i):
        """Return the value at index i if it has not been deleted.

        Args:
            i (int): The i input used by this function.

        Returns:
            object: The value produced by this function.
        """
        if self.deleted[i]:
            raise IndexError("That position has been deleted")
        return self.arr[i]

    def __iter__(self):
        """Yield only the values that are still active.

        Returns:
            generator: A generator that yields values one at a time.
        """
        for index, value in enumerate(self.arr):
            if not self.deleted[index]:
                yield value


def main():
    """Run the small demonstration for this teaching example.

    Returns:
        None: This function updates data or prints results and does not return a value.
    """
    arr = [1, 2, 3, 4, 5]
    delete_index = 2

    print("Delete from an unsorted list:", delete_element(arr.copy(), delete_index))

    sorted_arr = SortedArray(arr)
    sorted_arr.delete(delete_index)
    print("Number of active values:", len(sorted_arr))
    print("Active values:", list(sorted_arr))
    print("Index of 4:", sorted_arr.search(4))


if __name__ == "__main__":
    main()
