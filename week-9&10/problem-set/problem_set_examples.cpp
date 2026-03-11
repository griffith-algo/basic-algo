#include <algorithm>
#include <iostream>
#include <numeric>
#include <tuple>
#include <vector>

using namespace std;

class Graph {
public:
    /**
     * @brief Run the Graph step used in this example.
     * @param vertices int The vertices value used by this function.
     * @return explicit The value produced by this function.
     */
    explicit Graph(int vertices) : vertices_(vertices), parent_(vertices), rank_(vertices, 0) {
        iota(parent_.begin(), parent_.end(), 0);
    }

    /**
     * @brief Run the add edge step used in this example.
     * @param u int The u value used by this function.
     * @param v int The v value used by this function.
     * @param weight int The weight value used by this function.
     * @return void This function updates data or prints results and does not return a value.
     */
    void add_edge(int u, int v, int weight) {
        edges_.push_back({u, v, weight});
    }

    /**
     * @brief Run the maximum spanning tree step used in this example.
     * @return vector<tuple<int, int, int>> The vector produced by the algorithm.
     */
    vector<tuple<int, int, int>> maximum_spanning_tree() {
        sort(edges_.begin(), edges_.end(), [](const auto& left, const auto& right) {
            return get<2>(left) > get<2>(right);
        });

        vector<tuple<int, int, int>> result;
        for (const auto& [u, v, weight] : edges_) {
            int u_root = find(u);
            int v_root = find(v);
            if (u_root != v_root) {
                result.push_back({u, v, weight});
                unite(u_root, v_root);
                if (result.size() == static_cast<size_t>(vertices_ - 1)) break;
            }
        }
        return result;
    }

private:
    /**
     * @brief Run the find step used in this example.
     * @param node int The node currently processed by the function.
     * @return int The integer result produced by the algorithm.
     */
    int find(int node) {
        if (parent_[node] != node) {
            parent_[node] = find(parent_[node]);
        }
        return parent_[node];
    }

    /**
     * @brief Run the unite step used in this example.
     * @param left int The left-side data or left boundary used by the algorithm.
     * @param right int The right-side data or right boundary used by the algorithm.
     * @return void This function updates data or prints results and does not return a value.
     */
    void unite(int left, int right) {
        if (rank_[left] < rank_[right]) swap(left, right);
        parent_[right] = left;
        if (rank_[left] == rank_[right]) ++rank_[left];
    }

    int vertices_;
    vector<tuple<int, int, int>> edges_;
    vector<int> parent_;
    vector<int> rank_;
};

/**
 * @brief Run the small demonstration for this teaching example.
 * @return int The integer result produced by the algorithm.
 */
int main() {
    Graph graph(4);
    graph.add_edge(0, 1, 10);
    graph.add_edge(0, 2, 6);
    graph.add_edge(0, 3, 5);
    graph.add_edge(1, 3, 15);
    graph.add_edge(2, 3, 4);

    cout << "Edges in the maximum spanning tree are:\n";
    for (const auto& [u, v, weight] : graph.maximum_spanning_tree()) {
        cout << u << " - " << v << ": " << weight << '\n';
    }
    return 0;
}
