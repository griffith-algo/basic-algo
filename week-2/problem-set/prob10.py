"""Prob10 example.

This file belongs to the week 2 data-structure and graph practice solutions. It uses tower_of_hanoi to illustrate the main idea with a small runnable example.
"""

def tower_of_hanoi(n, src, dest, aux):
    """Solve the Tower of Hanoi problem iteratively using an explicit stack.

    Args:
        n (int): The n input used by this function.
        src (str): The src input used by this function.
        dest (str): The dest input used by this function.
        aux (str): The aux input used by this function.

    Returns:
        None: This function updates data or prints results and does not return a value.
    """
    stack = []
    stack.append((n, src, dest, aux))

    while stack:
        n, src, dest, aux = stack.pop()
        if n == 1:
            print(f"Move disk from {src} to {dest}")
        else:
            stack.append((n-1, aux, dest, src))
            stack.append((1, src, dest, aux))
            stack.append((n-1, src, aux, dest))

# Example usage:
tower_of_hanoi(3, 'A', 'C', 'B')
