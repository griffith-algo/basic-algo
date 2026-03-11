"""Prob12 example.

This file belongs to the week 7 and 8 tree and hashing practice solutions. It uses print_heap, is_min_heap, is_max_heap to illustrate the main idea with a small runnable example.
"""

def print_heap(heap, index=0, indent=0):
    """Print the heap sideways so its tree shape is easier to see.

    Args:
        heap (list): The heap values used in the example.
        index (int): The index input used by this function.
        indent (int): The indent input used by this function.

    Returns:
        None: This function updates data or prints results and does not return a value.
    """
    if index < len(heap):
        print_heap(heap, 2 * index + 2, indent + 2)
        print(" " * indent + str(heap[index]))
        print_heap(heap, 2 * index + 1, indent + 2)

# Min-Heap (sorted array in non-descending order)
min_heap_array = [1, 2, 3, 4, 5, 6, 7]
print("Min-Heap:")
print_heap(min_heap_array)
print()

# Max-Heap (sorted array in non-ascending order)
max_heap_array = [7, 6, 5, 4, 3, 2, 1]
print("Max-Heap:")
print_heap(max_heap_array)

def is_min_heap(H):
    """Return True when the array satisfies the min-heap property.

    Args:
        H (object): The H input used by this function.

    Returns:
        bool: True when the required condition is satisfied, otherwise False.
    """
    n = len(H)
    is_heap = True

    for i in range(1, (n-1) // 2 + 1):
        left_child = 2 * i
        right_child = 2 * i + 1

        if H[i-1] > H[left_child-1] or (right_child <= n and H[i-1] > H[right_child-1]):
            is_heap = False
            break

    return is_heap

def is_max_heap(H):
    """Return True when the array satisfies the max-heap property.

    Args:
        H (object): The H input used by this function.

    Returns:
        bool: True when the required condition is satisfied, otherwise False.
    """
    n = len(H)
    is_heap = True

    for i in range(1, (n-1) // 2 + 1):
        left_child = 2 * i
        right_child = 2 * i + 1

        if H[i-1] < H[left_child-1] or (right_child <= n and H[i-1] < H[right_child-1]):
            is_heap = False
            break

    return is_heap

# Example 1: Valid max-heap
max_heap_array1 = [9, 7, 6, 4, 3, 5, 1]
print("Example 1 (Valid max-heap):", is_max_heap(max_heap_array1))  # Output: True

# Example 2: Invalid max-heap
max_heap_array2 = [9, 7, 6, 4, 3, 5, 10]
print("Example 2 (Invalid max-heap):", is_max_heap(max_heap_array2))  # Output: False

# Example 3: Valid max-heap (single element)
max_heap_array3 = [1]
print("Example 3 (Valid max-heap, single element):", is_max_heap(max_heap_array3))  # Output: True

# Example 4: Valid max-heap (sorted in non-ascending order)
max_heap_array4 = [7, 6, 5, 4, 3, 2, 1]
print("Example 4 (Valid max-heap, sorted in non-ascending order):", is_max_heap(max_heap_array4))  # Output: True
