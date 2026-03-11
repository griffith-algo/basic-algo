"""Prob1 example.

This file belongs to the week 2 data-structure and graph practice solutions. It
compares array-based searches with linked-list and skip-list style searches.
"""


class Node:
    """Store one node used by the surrounding example."""

    def __init__(self, value, index):
        """Store the value, its original index, and links to the next levels.

        Args:
            value (int): The value input used by this function.
            index (int): The index input used by this function.

        Returns:
            None: This function updates data or prints results and does not return a value.
        """
        self.value = value
        self.index = index
        self.next = None
        self.down = None


class LinkedList:
    """Store a simple singly linked list."""

    def __init__(self, values):
        """Build the linked list from the values in order.

        Args:
            values (list): The list of values processed by the function.

        Returns:
            None: This function updates data or prints results and does not return a value.
        """
        self.head = None
        self.tail = None
        self.size = 0

        for value in values:
            self.append(value)

    def append(self, value):
        """Append a new node to the end of the linked list.

        Args:
            value (int): The value input used by this function.

        Returns:
            None: This function updates data or prints results and does not return a value.
        """
        new_node = Node(value, self.size)

        if self.head is None:
            self.head = new_node
            self.tail = new_node
        else:
            self.tail.next = new_node
            self.tail = new_node

        self.size += 1


def binary_search(arr, target):
    """Search a sorted list by repeatedly halving the search range.

    Args:
        arr (list): The list being processed by the algorithm.
        target (object): The target input used by this function.

    Returns:
        int: The integer result produced by the algorithm.
    """
    left = 0
    right = len(arr) - 1

    while left <= right:
        mid = (left + right) // 2
        if arr[mid] == target:
            return mid
        if arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1

    return -1


def interpolation_search(arr, target):
    """Search a sorted list by estimating where the target should appear.

    Args:
        arr (list): The list being processed by the algorithm.
        target (object): The target input used by this function.

    Returns:
        int: The integer result produced by the algorithm.
    """
    left = 0
    right = len(arr) - 1

    while left <= right and arr[left] <= target <= arr[right]:
        if arr[left] == arr[right]:
            return left if arr[left] == target else -1

        pos = left + ((target - arr[left]) * (right - left)) // (arr[right] - arr[left])

        if arr[pos] == target:
            return pos
        if arr[pos] < target:
            left = pos + 1
        else:
            right = pos - 1

    return -1


def linear_search(head, target):
    """Scan a linked list from left to right until the target is found.

    Args:
        head (object): The first node in the linked structure.
        target (object): The target input used by this function.

    Returns:
        int: The integer result produced by the algorithm.
    """
    current = head

    while current is not None and current.value <= target:
        if current.value == target:
            return current.index
        current = current.next

    return -1


def build_skip_list(values, step=2):
    """Build a two-level skip list so the search demo can move across and down.

    Args:
        values (list): The list of values processed by the function.
        step (int): The step input used by this function.

    Returns:
        tuple: The tuple of values produced by the algorithm.
    """
    bottom_nodes = [Node(value, index) for index, value in enumerate(values)]

    for index in range(len(bottom_nodes) - 1):
        bottom_nodes[index].next = bottom_nodes[index + 1]

    express_nodes = []
    for index in range(0, len(values), step):
        express_node = Node(values[index], index)
        express_node.down = bottom_nodes[index]
        express_nodes.append(express_node)

    for index in range(len(express_nodes) - 1):
        express_nodes[index].next = express_nodes[index + 1]

    return express_nodes[0], bottom_nodes[0]


def skip_list_search(head, target):
    """Illustrate how skip-list style search can move across and down levels.

    Args:
        head (object): The first node in the linked structure.
        target (object): The target input used by this function.

    Returns:
        int: The integer result produced by the algorithm.
    """
    current = head

    while current is not None:
        while current.next is not None and current.next.value <= target:
            current = current.next

        if current.value == target:
            return current.index

        current = current.down

    return -1


def main():
    """Run the small demonstration for this teaching example.

    Returns:
        None: This function updates data or prints results and does not return a value.
    """
    arr = [1, 3, 5, 7, 9, 11, 13, 15, 17]
    linked_list = LinkedList(arr)
    skip_head, _ = build_skip_list(arr)

    print("Binary search:", binary_search(arr, 11))
    print("Interpolation search:", interpolation_search(arr, 11))
    print("Linear search on linked list:", linear_search(linked_list.head, 11))
    print("Skip-list search:", skip_list_search(skip_head, 11))


if __name__ == "__main__":
    main()
