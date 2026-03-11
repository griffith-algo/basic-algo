"""Prob8 example.

This file belongs to the week 2 data-structure and graph practice solutions. It uses Queue to illustrate the main idea with a small runnable example.
"""

class Queue:
    """Queue implemented with two stacks."""
    def __init__(self):
        """Run the   init   step used in this example.

        Returns:
            None: This function updates data or prints results and does not return a value.
        """
        self.enqueue_stack = []
        self.dequeue_stack = []

    def enqueue(self, item):
        """Insert a new item into the data structure.

        Args:
            item (object): The item input used by this function.

        Returns:
            None: This function updates data or prints results and does not return a value.
        """
        self.enqueue_stack.append(item)

    def dequeue(self):
        """Remove and return the next item from the data structure.

        Returns:
            object: The value produced by this function.
        """
        if not self.dequeue_stack:
            while self.enqueue_stack:
                self.dequeue_stack.append(self.enqueue_stack.pop())
        if not self.dequeue_stack:
            raise IndexError("Queue is empty")
        return self.dequeue_stack.pop()

    def is_empty(self):
        """Run the is empty step used in this example.

        Returns:
            bool: True when the required condition is satisfied, otherwise False.
        """
        return len(self.enqueue_stack) == 0 and len(self.dequeue_stack) == 0

q = Queue()
q.enqueue(1)
q.enqueue(2)
q.enqueue(3)
print(q.dequeue()) # Output: 1
q.enqueue(4)
print(q.dequeue()) # Output: 2
print(q.dequeue()) # Output: 3
print(q.dequeue()) # Output: 4
print(q.is_empty()) # Output: True
