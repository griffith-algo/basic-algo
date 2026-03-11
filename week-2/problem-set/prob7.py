"""Prob7 example.

This file belongs to the week 2 data-structure and graph practice solutions. It uses sort_stack to illustrate the main idea with a small runnable example.
"""

def sort_stack(S):
    """Sort a stack so that the smallest value ends up on top.

    Args:
        S (object): The S input used by this function.

    Returns:
        list: The list produced by the algorithm.
    """
    T = []
    while S:
        x = S.pop()
        while T and T[-1] < x:
            S.append(T.pop())
        T.append(x)
    while T:
        S.append(T.pop())
    return S

S = [1, 3, 2, 5, 4]
print(sort_stack(S)) # Output: [1, 2, 3, 4, 5]
