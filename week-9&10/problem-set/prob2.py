"""Prob2 example.

This file belongs to the week 9 and 10 spanning-tree practice solutions. It uses Graph to illustrate the main idea with a small runnable example.
"""

from collections import defaultdict

class Graph:
    """Weighted graph used to demonstrate spanning-tree construction."""
    def __init__(self, vertices):
        """Run the   init   step used in this example.

        Args:
            vertices (int): The vertices input used by this function.

        Returns:
            None: This function updates data or prints results and does not return a value.
        """
        self.V = vertices
        self.graph = []

    def add_edge(self, u, v, w):
        """Add a weighted edge to the graph.

        Args:
            u (object): The u input used by this function.
            v (object): The v input used by this function.
            w (object): The w input used by this function.

        Returns:
            None: This function updates data or prints results and does not return a value.
        """
        self.graph.append((u, v, w))

    def find(self, parent, i):
        """Search the text for every occurrence of the pattern.

        Args:
            parent (object): The parent input used by this function.
            i (int): The i input used by this function.

        Returns:
            int: The integer result produced by the algorithm.
        """
        if parent[i] == i:
            return i
        return self.find(parent, parent[i])

    def union(self, parent, rank, x, y):
        """Merge the two sets that contain the given vertices.

        Args:
            parent (object): The parent input used by this function.
            rank (object): The rank input used by this function.
            x (int): The x input used by this function.
            y (int): The y input used by this function.

        Returns:
            None: This function updates data or prints results and does not return a value.
        """
        x_root = self.find(parent, x)
        y_root = self.find(parent, y)

        if rank[x_root] < rank[y_root]:
            parent[x_root] = y_root
        elif rank[x_root] > rank[y_root]:
            parent[y_root] = x_root
        else:
            parent[y_root] = x_root
            rank[x_root] += 1

    def maximum_spanning_tree(self):
        """Build a maximum spanning tree using Kruskal's algorithm.

        Returns:
            list: The list produced by the algorithm.
        """
        result = []
        i = 0
        e = 0

        self.graph = sorted(self.graph, key=lambda item: item[2], reverse=True)

        parent = []
        rank = []

        for node in range(self.V):
            parent.append(node)
            rank.append(0)

        while e < self.V - 1:
            u, v, w = self.graph[i]
            i += 1
            u_root = self.find(parent, u)
            v_root = self.find(parent, v)

            if u_root != v_root:
                e += 1
                result.append((u, v, w))
                self.union(parent, rank, u_root, v_root)

        return result

# Example
g = Graph(4)
g.add_edge(0, 1, 10)
g.add_edge(0, 2, 6)
g.add_edge(0, 3, 5)
g.add_edge(1, 3, 15)
g.add_edge(2, 3, 4)

print("Edges in the maximum spanning tree are:")
for u, v, weight in g.maximum_spanning_tree():
    print("%d - %d: %d" % (u, v, weight))