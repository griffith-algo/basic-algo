/**
 * @file maze.cpp
 * @brief C++ version of the recursive maze backtracking example.
 */

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

/**
 * @brief Return every open neighbour of the current maze cell.
 * @param maze const vector<vector<int>>& Maze grid where 1 means open and 0 means blocked.
 * @param position pair<int, int> Current cell as (row, column).
 * @return vector<pair<int, int>> Open neighbouring cells reachable in one step.
 */
vector<pair<int, int>> get_neighbors(const vector<vector<int>>& maze, pair<int, int> position) {
    int row = position.first;
    int col = position.second;
    vector<pair<int, int>> neighbors;

    if (row > 0 && maze[row - 1][col] == 1) {
        neighbors.push_back({row - 1, col});
    }
    if (row < static_cast<int>(maze.size()) - 1 && maze[row + 1][col] == 1) {
        neighbors.push_back({row + 1, col});
    }
    if (col > 0 && maze[row][col - 1] == 1) {
        neighbors.push_back({row, col - 1});
    }
    if (col < static_cast<int>(maze[0].size()) - 1 && maze[row][col + 1] == 1) {
        neighbors.push_back({row, col + 1});
    }

    return neighbors;
}

/**
 * @brief Use recursive backtracking to search for a path through the maze.
 * @param maze const vector<vector<int>>& Maze grid where 1 means open and 0 means blocked.
 * @param start pair<int, int> Current cell visited by this recursive call.
 * @param end pair<int, int> Goal cell the algorithm wants to reach.
 * @param path vector<pair<int, int>>& Path built so far.
 * @return bool True when a path from start to end has been found, otherwise false.
 */
bool find_path(const vector<vector<int>>& maze,
               pair<int, int> start,
               pair<int, int> end,
               vector<pair<int, int>>& path) {
    path.push_back(start);

    if (start == end) {
        return true;
    }

    for (const auto& neighbor : get_neighbors(maze, start)) {
        if (find(path.begin(), path.end(), neighbor) == path.end()) {
            if (find_path(maze, neighbor, end, path)) {
                return true;
            }
        }
    }

    path.pop_back();
    return false;
}

/**
 * @brief Run the maze-search demonstration.
 * @return int Exit status code returned to the operating system.
 */
int main() {
    vector<vector<int>> maze = {
        {1, 1, 1, 0, 1},
        {1, 0, 1, 0, 1},
        {1, 0, 1, 1, 1},
        {1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1}
    };

    vector<pair<int, int>> path;
    if (find_path(maze, {0, 0}, {4, 4}, path)) {
        cout << "Path found: ";
        for (const auto& [row, col] : path) {
            cout << '(' << row << ", " << col << ") ";
        }
        cout << '\n';
    } else {
        cout << "No path found.\n";
    }
    return 0;
}
