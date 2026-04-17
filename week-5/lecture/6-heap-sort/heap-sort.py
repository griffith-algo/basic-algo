def heapify(arr, n, i):
    # Find the largest element among root and its children
    """Restore the heap property for the subtree rooted at the given index.
    
    Args:
        arr (list): The list being processed by the algorithm.
        n (int): The size of the heap.
        i (int): The index of the root node of the current subtree.
    
    Returns:
        None: This function modifies the input list in-place.
    """
    largest = i  # Assume root is the largest
    l = 2 * i + 1  # Left child index
    r = 2 * i + 2  # Right child index

    # Check if the left child is larger than the root
    if l < n and arr[l] > arr[largest]:
        largest = l

    # Check if the right child is larger than the current largest
    if r < n and arr[r] > arr[largest]:
        largest = r

    # If the largest is not the root, swap and continue heapifying
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]  # Swap
        heapify(arr, n, largest)  # Recursively heapify the affected subtree


def heapSort(arr):
    """Sort the list in ascending order using heap sort.
    
    Args:
        arr (list): The list to be sorted.
    
    Returns:
        None: This function modifies the input list in-place.
    """
    n = len(arr)

    # Build max heap
    for i in range(n//2 - 1, -1, -1):  # Start from the last non-leaf node
        heapify(arr, n, i)

    # Extract elements one by one from the heap and rebuild heap
    for i in range(n-1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]  # Swap the root (max element) with the last element

        # Restore the heap property for the reduced heap
        heapify(arr, i, 0)
  

arr = [1, 12, 9, 5, 6, 10]
heapSort(arr)
n = len(arr)
print("Sorted array is:")
for i in range(n):
    print("%d " % arr[i], end='')  # Print the sorted array