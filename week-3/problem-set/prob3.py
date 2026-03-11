"""Prob3 example.

This file belongs to the week 3 problem-set solutions on sorting, greedy algorithms, and dynamic programming. It uses alternating_disks to illustrate the main idea with a small runnable example.
"""

def alternating_disks(disks):
    """Group identical disks together by swapping neighbouring positions.

    Args:
        disks (object): The disks input used by this function.

    Returns:
        list: The list produced by the algorithm.
    """
    n = len(disks) // 2
    while True:
        swapped = False
        for i in range(n*2 - 1):
            if disks[i] < disks[i+1]:
                disks[i], disks[i+1] = disks[i+1], disks[i]
                swapped = True
        if not swapped:
            break
    return disks

disks = ["D", "L", "D", "L", "D", "L", "D", "L"]
solved_disks = alternating_disks(disks)
print(solved_disks)