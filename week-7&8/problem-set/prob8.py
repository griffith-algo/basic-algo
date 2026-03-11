"""Prob8 example.

This file belongs to the week 7 and 8 tree and hashing practice solutions. It uses ChainingHashTable, is_distinct to illustrate the main idea with a small runnable example.
"""

class ChainingHashTable:
    """Simple hash table that resolves collisions with chaining."""
    def __init__(self, size=100):
        """Run the   init   step used in this example.

        Args:
            size (int): The size input used by this function.

        Returns:
            None: This function updates data or prints results and does not return a value.
        """
        self.size = size
        self.table = [[] for _ in range(size)]

    def hash_function(self, value):
        """Map a value to one bucket in the hash table.

        Args:
            value (int): The value input used by this function.

        Returns:
            int: The integer result produced by the algorithm.
        """
        return value % 2

    def insert(self, value):
        """Insert a new value into the hash table if it is not already present.

        Args:
            value (int): The value input used by this function.

        Returns:
            object: The value produced by this function.
        """
        index = self.hash_function(value)
        print(index)
        if value not in self.table[index]:
            self.table[index].append(value)
            return True
        else:
            return False

def is_distinct(lst):
    """Return True when the list contains no duplicate values.

    Args:
        lst (object): The lst input used by this function.

    Returns:
        bool: True when the required condition is satisfied, otherwise False.
    """
    hash_table = ChainingHashTable()
    for elem in lst:
        if not hash_table.insert(elem):
            return False
    return True

# Example usage
lst = [1, 11, 21, 31]
print(is_distinct(lst))  # Output: True