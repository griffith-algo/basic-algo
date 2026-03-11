"""Prob2 example.

This file belongs to the worked week 1 problem-set solutions. It uses toggle_lockers_from_scratch, toggle_lockers to illustrate the main idea with a small runnable example.
"""

def toggle_lockers_from_scratch(n):
    """Simulate every locker toggle exactly as described in the puzzle.

    Args:
        n (int): The n input used by this function.

    Returns:
        list: The list produced by the algorithm.
    """
    lockers = [False] * n
    for i in range(n):
        for j in range(i, n, i+1): # i+1: because we start at index 0th, we need to add value "1" to fit the problem.
            lockers[j] = not lockers[j]
    return lockers

def toggle_lockers(n):
    """Use the perfect-square observation to find which lockers stay open.

    Args:
        n (int): The n input used by this function.

    Returns:
        list: The list produced by the algorithm.
    """
    import math
    lockers = [False] * n
    open_lockers = []
    for i in range(1, int(math.sqrt(n))+1):
        open_lockers.append(i**2)
    open_lockers
    for open_locker in open_lockers:
        lockers[open_locker - 1] = True
    return lockers

n = 20
# toggled_lockers = toggle_lockers(n)
toggled_lockers = toggle_lockers_from_scratch(n)
opened_lockers = [index+1 for index, item in enumerate(toggled_lockers) if item == True]
closed_lockers = [index+1 for index, item in enumerate(toggled_lockers) if item == False]
print("Opened lockers: ", opened_lockers)
print("Closed lockers: ", closed_lockers)
print("Number of opened lockers: ", len(opened_lockers))