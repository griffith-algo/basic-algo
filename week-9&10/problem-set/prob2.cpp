/**
 * @file prob2.cpp
 * @brief C++ version of the maximum spanning-tree example.
 */

#include <algorithm>
#include <iostream>
#include <numeric>
#include <tuple>
#include <vector>

using namespace std;

class Graph {
public:
    /**
     * @brief Create an empty weighted graph with a fixed number of vertices.
     * @param vertices int Number of vertices in the graph.
     */
    explicit Graph(int vertices) : V(vertices) {}

    /**
     * @brief Add one weighted edge to the graph.
     * @param u int First endpoint of the edge.
     * @param v int Second endpoint of the edge.
     * @param w int Edge weight.
     * @return void This method updates the graph and does not return a value.
     */
    void add_edge(int u, int v, int w) {
        graph.push_back({u, v, w});
    }

    /**
     * @brief Find the representative of the set that contains i.
     * @param parent vector<int>& Parent array of the disjoint-set structure.
     * @param i int Vertex whose set representative is required.
     * @return int Representative of the set containing i.
     */
    int find(vector<int>& parent, int i) {
        if (parent[i] == i) {
            return i;
        }
        return find(parent, parent[i]);
    }

    /**
     * @brief Merge the two sets that contain x and y.
     * @param parent vector<int>& Parent array of the disjoint-set structure.
     * @param rank vector<int>& Rank array used for union by rank.
     * @param x int Representative of the first set.
     * @param y int Representative of the second set.
     * @return void This method updates the disjoint-set structure and does not return a value.
     */
    void unite(vector<int>& parent, vector<int>& rank, int x, int y) {
        int x_root = find(parent, x);
        int y_root = find(parent, y);

        if (rank[x_root] < rank[y_root]) {
            parent[x_root] = y_root;
        } else if (rank[x_root] > rank[y_root]) {
            parent[y_root] = x_root;
        } else {
            parent[y_root] = x_root;
            ++rank[x_root];
        }
    }

    /**
     * @brief Build a maximum spanning tree using Kruskal's algorithm.
     * @return vector<tuple<int, int, int>> Edges chosen for the maximum spanning tree.
     */
    vector<tuple<int, int, int>> maximum_spanning_tree() {
        vector<tuple<int, int, int>> result;
        vector<tuple<int, int, int>> sorted_edges = graph;
        sort(sorted_edges.begin(), sorted_edges.end(), [](const auto& left, const auto& right) {
            return get<2>(left) > get<2>(right);
        });

        vector<int> parent(V);
        vector<int> rank(V, 0);
        iota(parent.begin(), parent.end(), 0);

        int edges_used = 0;
        int edge_index = 0;
        while (edges_used < V - 1 && edge_index < static_cast<int>(sorted_edges.size())) {
            auto [u, v, w] = sorted_edges[edge_index++];
            int u_root = find(parent, u);
            int v_root = find(parent, v);

            if (u_root != v_root) {
                result.push_back({u, v, w});
                unite(parent, rank, u_root, v_root);
                ++edges_used;
            }
        }
        return result;
    }

private:
    int V;
    vector<tuple<int, int, int>> graph;
};

/**
 * @brief Run the maximum spanning-tree demonstration.
 * @return int Exit status code returned to the operating system.
 */
int main() {
    Graph g(4);
    g.add_edge(0, 1, 10);
    g.add_edge(0, 2, 6);
    g.add_edge(0, 3, 5);
    g.add_edge(1, 3, 15);
    g.add_edge(2, 3, 4);

    cout << "Edges in the maximum spanning tree are:\n";
    for (const auto& [u, v, weight] : g.maximum_spanning_tree()) {
        cout << u << " - " << v << ": " << weight << '\n';
    }
    return 0;
}
