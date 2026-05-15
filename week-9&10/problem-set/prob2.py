class Graph:
    """A weighted graph for finding a Maximum Spanning Tree using Kruskal's algorithm."""

    def __init__(self, vertices):
        # Number of vertices in the graph
        self.V = vertices

        # List of edges. Each edge is stored as: (u, v, weight)
        self.graph = []

    def add_edge(self, u, v, w):
        """Add an edge between vertex u and vertex v with weight w."""
        self.graph.append((u, v, w))

    def find(self, parent, i):
        """
        Find the root representative of the set containing vertex i.

        If parent[i] == i, then i is the root of its set.
        Otherwise, keep moving upward until we find the root.
        """
        if parent[i] == i:
            return i

        return self.find(parent, parent[i])

    def union(self, parent, rank, x, y):
        """
        Merge the two sets containing x and y.

        The rank array helps keep the tree shallow.
        The smaller-rank tree is attached under the larger-rank tree.
        """

        # Find the root of each set
        x_root = self.find(parent, x)
        y_root = self.find(parent, y)

        # If x's tree is shorter, attach it under y's tree
        if rank[x_root] < rank[y_root]:
            parent[x_root] = y_root

        # If y's tree is shorter, attach it under x's tree
        elif rank[x_root] > rank[y_root]:
            parent[y_root] = x_root

        # If both trees have the same rank, choose one as root
        # and increase its rank because the tree height may grow
        else:
            parent[y_root] = x_root
            rank[x_root] += 1

    def maximum_spanning_tree(self):
        """
        Build a Maximum Spanning Tree using Kruskal's algorithm.

        Steps:
        1. Sort edges from largest weight to smallest weight.
        2. Add an edge if it does not create a cycle.
        3. Stop when the tree has V - 1 edges.
        """

        result = []  # Stores edges selected for the maximum spanning tree
        i = 0        # Index for sorted edges
        e = 0        # Number of selected edges

        # Sort edges by weight in descending order for Maximum Spanning Tree
        self.graph = sorted(self.graph, key=lambda edge: edge[2], reverse=True)

        # Initially, each vertex is its own parent
        parent = []
        rank = []

        for node in range(self.V):
            parent.append(node)
            rank.append(0)

        # A spanning tree with V vertices must have exactly V - 1 edges
        while e < self.V - 1:
            u, v, w = self.graph[i]
            i += 1

            # Find the sets of u and v
            u_root = self.find(parent, u)
            v_root = self.find(parent, v)

            # If u and v are in different sets, adding this edge will not create a cycle
            if u_root != v_root:
                result.append((u, v, w))
                e += 1

                # Merge the two sets
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