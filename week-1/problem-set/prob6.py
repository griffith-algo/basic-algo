"""Prob6 example.

This file belongs to the worked week 1 problem-set solutions. It uses comparison_counting_sort to illustrate the main idea with a small runnable example.
"""

def comparison_counting_sort(A):
    """Sort the list by counting how many values are smaller than each element.

    Args:
        A (object): The A input used by this function.

    Returns:
        list: The list produced by the algorithm.
    """
    n = len(A)
    Count = [0] * n
    S = [0] * n
    
    for i in range(n):
        for j in range(i+1, n):
            if A[i] < A[j]:
                Count[j] += 1
            else:
                Count[i] += 1
                
    for i in range(n):
        S[Count[i]] = A[i]
        
    return S

A = [60,  35,  81,  98,  14,  47]
S = comparison_counting_sort(A)
print(S)  # Output: [1, 2, 5, 5, 6, 9]
