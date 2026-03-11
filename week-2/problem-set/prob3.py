"""Prob3 example.

This file belongs to the week 2 data-structure and graph practice solutions. It uses PriorityQueueUnsortedArray, PriorityQueueSortedArray, Node, PriorityQueueBinarySearchTree to illustrate the main idea with a small runnable example.
"""

class PriorityQueueUnsortedArray:
    """Priority queue implemented with an unsorted list."""
    def __init__(self):
        """Run the   init   step used in this example.

        Returns:
            None: This function updates data or prints results and does not return a value.
        """
        self.items = []
    
    def is_empty(self):
        """Run the is empty step used in this example.

        Returns:
            bool: True when the required condition is satisfied, otherwise False.
        """
        return len(self.items) == 0
    
    def enqueue(self, item, priority):
        """Insert a new item into the data structure.

        Args:
            item (object): The item input used by this function.
            priority (int): The priority input used by this function.

        Returns:
            None: This function updates data or prints results and does not return a value.
        """
        self.items.append((item, priority))
    
    def dequeue(self):
        """Remove and return the next item from the data structure.

        Returns:
            object: The value produced by this function.
        """
        if self.is_empty():
            return None
        highest_priority_item = self.items[0]
        for item, priority in self.items:
            if priority > highest_priority_item[1]:
                highest_priority_item = (item, priority)
        self.items.remove(highest_priority_item)
        return highest_priority_item[0]


class PriorityQueueSortedArray:
    """Priority queue implemented with a sorted list."""
    def __init__(self):
        """Run the   init   step used in this example.

        Returns:
            None: This function updates data or prints results and does not return a value.
        """
        self.items = []
    
    def is_empty(self):
        """Run the is empty step used in this example.

        Returns:
            bool: True when the required condition is satisfied, otherwise False.
        """
        return len(self.items) == 0
    
    def enqueue(self, item, priority):
        """Insert a new item into the data structure.

        Args:
            item (object): The item input used by this function.
            priority (int): The priority input used by this function.

        Returns:
            None: This function updates data or prints results and does not return a value.
        """
        self.items.append((item, priority))
        self.items = sorted(self.items, key=lambda x: x[1], reverse=True)
    
    def dequeue(self):
        """Remove and return the next item from the data structure.

        Returns:
            object: The value produced by this function.
        """
        if self.is_empty():
            return None
        return self.items.pop()[0]


class Node:
    """Store one node used by the surrounding example."""
    def __init__(self, item, priority):
        """Run the   init   step used in this example.

        Args:
            item (object): The item input used by this function.
            priority (int): The priority input used by this function.

        Returns:
            None: This function updates data or prints results and does not return a value.
        """
        self.item = item
        self.priority = priority
        self.left = None
        self.right = None
    
class PriorityQueueBinarySearchTree:
    """Priority queue implemented with a binary search tree."""
    def __init__(self):
        """Run the   init   step used in this example.

        Returns:
            None: This function updates data or prints results and does not return a value.
        """
        self.root = None
    
    def is_empty(self):
        """Run the is empty step used in this example.

        Returns:
            bool: True when the required condition is satisfied, otherwise False.
        """
        return self.root is None
    
    def enqueue(self, item, priority):
        """Insert a new item into the data structure.

        Args:
            item (object): The item input used by this function.
            priority (int): The priority input used by this function.

        Returns:
            None: This function updates data or prints results and does not return a value.
        """
        if self.is_empty():
            self.root = Node(item, priority)
        else:
            self._enqueue_helper(item, priority, self.root)
    
    def _enqueue_helper(self, item, priority, node):
        """Run the  enqueue helper step used in this example.

        Args:
            item (object): The item input used by this function.
            priority (int): The priority input used by this function.
            node (object): The node currently processed by the function.

        Returns:
            None: This function updates data or prints results and does not return a value.
        """
        if priority > node.priority:
            if node.left is None:
                node.left = Node(item, priority)
            else:
                self._enqueue_helper(item, priority, node.left)
        else:
            if node.right is None:
                node.right = Node(item, priority)
            else:
                self._enqueue_helper(item, priority, node.right)
    
    def dequeue(self):
        """Remove and return the next item from the data structure.

        Returns:
            object: The value produced by this function.
        """
        if self.is_empty():
            return None
        return self._dequeue_helper(self.root)[0]
    
    def _dequeue_helper(self, node):
        """Run the  dequeue helper step used in this example.

        Args:
            node (object): The node currently processed by the function.

        Returns:
            tuple: The tuple of values produced by the algorithm.
        """
        if node.left is None:
            self.root = node.right
            return (node.item, node.priority)
        else:
            item, priority = self._dequeue_helper(node.left)
            if node.left.left is None:
                node.left = node.left.right
            return (item, priority)


# Example usage
pq1 = PriorityQueueUnsortedArray()
pq1.enqueue("Task 1", 3)
pq1.enqueue("Task 2", 1)
pq1.enqueue("Task 3", 2)
print(pq1.dequeue())  # "Task 1"
print(pq1.dequeue())  # "Task 3"
print(pq1.dequeue())  # "Task 2"

pq2 = PriorityQueueSortedArray()
pq2.enqueue("Task 1", 3)
pq2.enqueue("Task 2", 1)
pq2.enqueue("Task 3", 2)
print(pq2.dequeue())  # "Task 1"
print(pq2.dequeue())  # "Task 3"
print(pq2.dequeue())  # "Task 2"

pq3 = PriorityQueueBinarySearchTree()
pq3.enqueue("Task 1", 3)
pq3.enqueue("Task 2", 1)
pq3.enqueue("Task 3", 2)
print(pq3.dequeue())  # "Task 1"
print(pq3.dequeue())  # "Task 3"
print(pq3.dequeue())