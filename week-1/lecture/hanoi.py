"""Hanoi example.

This file belongs to the introductory lecture examples on recursion, searching, and simple sorting. It uses hanoi to illustrate the main idea with a small runnable example.
"""

def hanoi(n, source, target, auxiliary):
    """Move a stack of disks from the source peg to the target peg using an auxiliary peg.

    Args:
        n (int): The n input used by this function.
        source (object): The source input used by this function.
        target (object): The target input used by this function.
        auxiliary (object): The auxiliary input used by this function.

    Returns:
        None: This function updates data or prints results and does not return a value.
    """
    if n > 0:
        # Move n-1 disks from the source to the auxiliary peg
        hanoi(n-1, source, auxiliary, target)
        
        # Move the largest disk from the source to the target peg
        target.append(source.pop())
        print("Move disk", n, "from", source, "to", target)
        
        # Move the n-1 disks from the auxiliary peg to the target peg
        hanoi(n-1, auxiliary, target, source)
        
# Example usage:
source = [3, 2, 1]
target = []
auxiliary = []
hanoi(len(source), source, target, auxiliary)