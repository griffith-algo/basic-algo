/**
 * @file tsp.cpp
 * @brief C++ version of the backtracking travelling-salesperson example.
 */

#include <climits>
#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Search for the shortest travelling-salesperson tour using backtracking.
 * @param distances const vector<vector<int>>& Matrix of pairwise city distances.
 * @param current_city int City visited by the current recursive call.
 * @param visited vector<bool>& Flags showing which cities are already in the current path.
 * @param path vector<int>& Current tour prefix.
 * @param current_distance int Distance accumulated so far.
 * @param shortest_path vector<int>& Best path found so far.
 * @param shortest_distance int& Best tour distance found so far.
 * @return void This function updates shortest_path and shortest_distance in place.
 */
void tsp_backtrack(const vector<vector<int>>& distances,
                   int current_city,
                   vector<bool>& visited,
                   vector<int>& path,
                   int current_distance,
                   vector<int>& shortest_path,
                   int& shortest_distance) {
    path.push_back(current_city);
    visited[current_city] = true;

    if (path.size() == distances.size()) {
        int total_distance = current_distance + distances[current_city][0];
        if (total_distance < shortest_distance) {
            shortest_distance = total_distance;
            shortest_path = path;
        }
    } else {
        for (int neighbor = 0; neighbor < static_cast<int>(distances.size()); ++neighbor) {
            if (!visited[neighbor]) {
                tsp_backtrack(distances,
                              neighbor,
                              visited,
                              path,
                              current_distance + distances[current_city][neighbor],
                              shortest_path,
                              shortest_distance);
            }
        }
    }

    path.pop_back();
    visited[current_city] = false;
}

/**
 * @brief Run the backtracking TSP demonstration.
 * @return int Exit status code returned to the operating system.
 */
int main() {
    vector<vector<int>> distances = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    int start_city = 0;
    vector<bool> visited(distances.size(), false);
    vector<int> path;
    vector<int> shortest_path;
    int shortest_distance = INT_MAX;

    tsp_backtrack(distances, start_city, visited, path, 0, shortest_path, shortest_distance);

    cout << "Shortest path: ";
    for (int city : shortest_path) {
        cout << city << ' ';
    }
    cout << "\nShortest distance: " << shortest_distance << '\n';
    return 0;
}
