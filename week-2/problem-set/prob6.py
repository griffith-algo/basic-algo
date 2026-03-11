"""Prob6 example.

This file belongs to the week 2 data-structure and graph practice solutions. It uses reverse_stack_with_two_stacks, reverse_stack_with_one_queue, reverse_stack_with_one_stack to illustrate the main idea with a small runnable example.
"""

def reverse_stack_with_two_stacks(S):
    """Reverse a stack using two temporary stacks.

    Args:
        S (object): The S input used by this function.

    Returns:
        list: The list produced by the algorithm.
    """
    R = []
    T = []
    while S:
        R.append(S.pop())
    while R:
        T.append(R.pop())
    while T:
        S.append(T.pop())
    return S

def reverse_stack_with_one_queue(S):
    """Reverse a stack using one queue.

    Args:
        S (object): The S input used by this function.

    Returns:
        list: The list produced by the algorithm.
    """
    Q = []
    while S:
        Q.append(S.pop())
    while Q:
        S.append(Q.pop(0))
    return S

def reverse_stack_with_one_stack(S):
    """Reverse a stack using one additional stack.

    Args:
        S (object): The S input used by this function.

    Returns:
        list: The list produced by the algorithm.
    """
    T = []
    while S:
        x = S.pop()
        while T and T[-1] > x:
            S.append(T.pop())
        T.append(x)
    while T:
        S.append(T.pop())
    return S

# example usage of reverse_stack_with_two_stacks
S = [1, 2, 3, 4, 5]
print(reverse_stack_with_two_stacks(S)) # Output: [5, 4, 3, 2, 1]

# example usage of reverse_stack_with_one_queue
S = [1, 2, 3, 4, 5]
print(reverse_stack_with_one_queue(S)) # Output: [5, 4, 3, 2, 1]

# example usage of reverse_stack_with_one_stack
S = [1, 2, 3, 4, 5]
print(reverse_stack_with_one_stack(S)) # Output: [5, 4, 3, 2, 1]
