/**
 * @file graph.cpp
 * @brief Console-based C++ equivalent of the weighted-graph visualisation example.
 */

#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

/**
 * @brief Convert a weighted adjacency matrix into a list of directed edges.
 * @param adj_matrix const vector<vector<int>>& Square matrix of edge weights. A value of 0 means no self-loop edge is printed.
 * @return vector<tuple<int, int, int>> Tuples of (from, to, weight) for every non-zero edge.
 */
vector<tuple<int, int, int>> adjacency_matrix_to_edges(const vector<vector<int>>& adj_matrix) {
    vector<tuple<int, int, int>> edges;
    for (int row = 0; row < static_cast<int>(adj_matrix.size()); ++row) {
        for (int col = 0; col < static_cast<int>(adj_matrix[row].size()); ++col) {
            if (row != col && adj_matrix[row][col] != 0) {
                edges.push_back({row, col, adj_matrix[row][col]});
            }
        }
    }
    return edges;
}

/**
 * @brief Run the weighted-graph demonstration.
 * @return int Exit status code returned to the operating system.
 */
int main() {
    vector<vector<int>> adj_matrix = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    cout << "Weighted adjacency matrix:\n";
    for (const auto& row : adj_matrix) {
        for (int value : row) {
            cout << value << ' ';
        }
        cout << '\n';
    }

    cout << "\nDirected weighted edges:\n";
    for (const auto& [from, to, weight] : adjacency_matrix_to_edges(adj_matrix)) {
        cout << from << " -> " << to << " (weight " << weight << ")\n";
    }
    return 0;
}
