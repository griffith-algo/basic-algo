/**
 * @file tsp_permutations.cpp
 * @brief C++ version of the brute-force travelling-salesperson example.
 */

#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

/**
 * @brief Return the total distance of one travelling-salesperson tour.
 * @param path const vector<int>& Order in which the cities are visited.
 * @param distances const vector<vector<int>>& Matrix of pairwise city distances.
 * @return int Total distance of the closed tour defined by path.
 */
int path_distance(const vector<int>& path, const vector<vector<int>>& distances) {
    int total_distance = 0;
    for (size_t index = 0; index + 1 < path.size(); ++index) {
        total_distance += distances[path[index]][path[index + 1]];
    }
    total_distance += distances[path.back()][path.front()];
    return total_distance;
}

/**
 * @brief Run the brute-force TSP demonstration.
 * @return int Exit status code returned to the operating system.
 */
int main() {
    vector<vector<int>> distances = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    vector<int> path = {0, 1, 2, 3};
    int shortest_distance = numeric_limits<int>::max();
    vector<int> shortest_path;

    do {
        int distance = path_distance(path, distances);
        if (distance < shortest_distance) {
            shortest_distance = distance;
            shortest_path = path;
        }
    } while (next_permutation(path.begin(), path.end()));

    cout << "Shortest path: ";
    for (int city : shortest_path) {
        cout << city << ' ';
    }
    cout << "\nShortest distance: " << shortest_distance << '\n';
    return 0;
}
