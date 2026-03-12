/**
 * @file prob2.cpp
 * @brief C++ version of the graph-representation checks.
 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Build an adjacency matrix for an undirected graph.
 * @param num_vertices int Number of vertices in the graph.
 * @param edges const vector<pair<int, int>>& List of undirected edges as vertex pairs.
 * @return vector<vector<int>> Square matrix where 1 means an edge exists and 0 means no edge exists.
 */
vector<vector<int>> create_adjacency_matrix(int num_vertices, const vector<pair<int, int>>& edges) {
    vector<vector<int>> matrix(num_vertices, vector<int>(num_vertices, 0));
    for (const auto& edge : edges) {
        matrix[edge.first][edge.second] = 1;
        matrix[edge.second][edge.first] = 1;
    }
    return matrix;
}

/**
 * @brief Build an adjacency list for an undirected graph.
 * @param num_vertices int Number of vertices in the graph.
 * @param edges const vector<pair<int, int>>& List of undirected edges as vertex pairs.
 * @return vector<vector<int>> Adjacency list where each row stores the neighbours of one vertex.
 */
vector<vector<int>> create_adjacency_list(int num_vertices, const vector<pair<int, int>>& edges) {
    vector<vector<int>> graph(num_vertices);
    for (const auto& edge : edges) {
        graph[edge.first].push_back(edge.second);
        graph[edge.second].push_back(edge.first);
    }
    return graph;
}

/**
 * @brief Check whether a graph contains every possible edge.
 * @param matrix_or_list const vector<vector<int>>& Graph stored as an adjacency matrix or an adjacency list.
 * @param is_matrix bool True when matrix_or_list is an adjacency matrix, false when it is an adjacency list.
 * @return bool True when the graph is complete, otherwise false.
 */
bool is_complete(const vector<vector<int>>& matrix_or_list, bool is_matrix) {
    if (is_matrix) {
        for (int i = 0; i < static_cast<int>(matrix_or_list.size()); ++i) {
            for (int j = 0; j < static_cast<int>(matrix_or_list[i].size()); ++j) {
                if (i != j && matrix_or_list[i][j] == 0) {
                    return false;
                }
            }
        }
        return true;
    }

    int num_vertices = static_cast<int>(matrix_or_list.size());
    for (int i = 0; i < num_vertices; ++i) {
        if (static_cast<int>(matrix_or_list[i].size()) != num_vertices - 1) {
            return false;
        }
    }
    return true;
}

/**
 * @brief Check whether a graph contains a self-loop.
 * @param matrix_or_list const vector<vector<int>>& Graph stored as an adjacency matrix or an adjacency list.
 * @param is_matrix bool True when matrix_or_list is an adjacency matrix, false when it is an adjacency list.
 * @return bool True when at least one self-loop exists, otherwise false.
 */
bool has_loop(const vector<vector<int>>& matrix_or_list, bool is_matrix) {
    if (is_matrix) {
        for (int i = 0; i < static_cast<int>(matrix_or_list.size()); ++i) {
            if (matrix_or_list[i][i] == 1) {
                return true;
            }
        }
        return false;
    }

    for (int i = 0; i < static_cast<int>(matrix_or_list.size()); ++i) {
        for (int neighbour : matrix_or_list[i]) {
            if (neighbour == i) {
                return true;
            }
        }
    }
    return false;
}

/**
 * @brief Check whether a graph contains an isolated vertex.
 * @param matrix_or_list const vector<vector<int>>& Graph stored as an adjacency matrix or an adjacency list.
 * @param is_matrix bool True when matrix_or_list is an adjacency matrix, false when it is an adjacency list.
 * @return bool True when at least one vertex has no neighbours, otherwise false.
 */
bool has_isolated_vertex(const vector<vector<int>>& matrix_or_list, bool is_matrix) {
    if (is_matrix) {
        for (const auto& row : matrix_or_list) {
            bool isolated = true;
            for (int value : row) {
                if (value == 1) {
                    isolated = false;
                    break;
                }
            }
            if (isolated) {
                return true;
            }
        }
        return false;
    }

    for (const auto& row : matrix_or_list) {
        if (row.empty()) {
            return true;
        }
    }
    return false;
}

/**
 * @brief Run the graph-representation demonstration.
 * @return int Exit status code returned to the operating system.
 */
int main() {
    vector<pair<int, int>> edges = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}, {2, 3}};
    int num_vertices = 4;

    vector<vector<int>> matrix = create_adjacency_matrix(num_vertices, edges);
    vector<vector<int>> graph = create_adjacency_list(num_vertices, edges);

    cout << "Adjacency Matrix:\n";
    cout << "The graph is complete: " << boolalpha << is_complete(matrix, true) << '\n';
    cout << "The graph has a loop: " << has_loop(matrix, true) << '\n';
    cout << "The graph has an isolated vertex: " << has_isolated_vertex(matrix, true) << '\n';
    cout << "Adjacency List complete check: " << is_complete(graph, false) << '\n';
    return 0;
}
