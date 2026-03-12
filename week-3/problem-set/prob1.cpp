/**
 * @file prob1.cpp
 * @brief C++ version of the network-topology identification example.
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * @brief Identify the topology represented by an adjacency matrix.
 * @param matrix const vector<vector<int>>& Adjacency matrix where 1 means a direct connection.
 * @return string Name of the detected topology, or "Unknown Topology" when no known pattern matches.
 */
string determine_topology(const vector<vector<int>>& matrix) {
    int n = static_cast<int>(matrix.size());

    bool is_ring = true;
    for (int i = 0; i < n; ++i) {
        int neighbors = count(matrix[i].begin(), matrix[i].end(), 1);
        if (neighbors != 2) {
            if (i == 0 || i == n - 1) {
                if (neighbors != 1) {
                    is_ring = false;
                }
            } else {
                is_ring = false;
            }
        }
    }
    if (is_ring) {
        return "Ring Topology";
    }

    bool is_star = true;
    int center = -1;
    for (int i = 0; i < n; ++i) {
        int neighbors = count(matrix[i].begin(), matrix[i].end(), 1);
        if (neighbors == n - 1) {
            if (center == -1) {
                center = i;
            } else {
                is_star = false;
            }
        } else if (neighbors != 1) {
            is_star = false;
        }
    }
    if (is_star) {
        return "Star Topology";
    }

    bool is_mesh = true;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j && matrix[i][j] == 0) {
                is_mesh = false;
            }
        }
    }
    if (is_mesh) {
        return "Fully Connected Mesh Topology";
    }

    return "Unknown Topology";
}

/**
 * @brief Run the topology-identification demonstrations.
 * @return int Exit status code returned to the operating system.
 */
int main() {
    vector<vector<int>> ring = {
        {0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 1, 0}
    };

    vector<vector<int>> star = {
        {0, 1, 1, 1},
        {1, 0, 0, 0},
        {1, 0, 0, 0},
        {1, 0, 0, 0}
    };

    vector<vector<int>> mesh = {
        {0, 1, 1, 1},
        {1, 0, 1, 1},
        {1, 1, 0, 1},
        {1, 1, 1, 0}
    };

    vector<vector<int>> unknown = {
        {0, 1, 0, 1},
        {1, 0, 0, 1},
        {0, 0, 0, 1},
        {1, 1, 1, 0}
    };

    cout << determine_topology(ring) << '\n';
    cout << determine_topology(star) << '\n';
    cout << determine_topology(mesh) << '\n';
    cout << determine_topology(unknown) << '\n';
    return 0;
}
