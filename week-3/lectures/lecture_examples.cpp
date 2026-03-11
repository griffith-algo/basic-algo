#include <algorithm>
#include <climits>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

/**
 * @brief Return the valid neighbouring positions in the maze.
 * @param maze const vector<vector<int>>& The maze value used by this function.
 * @param position pair<int, int> The position value used by this function.
 * @return vector<pair<int, int>> The vector produced by the algorithm.
 */
vector<pair<int, int>> get_neighbors(const vector<vector<int>>& maze, pair<int, int> position) {
    vector<pair<int, int>> neighbors;
    int row = position.first;
    int col = position.second;
    if (row > 0 && maze[row - 1][col] == 1) neighbors.push_back({row - 1, col});
    if (row + 1 < static_cast<int>(maze.size()) && maze[row + 1][col] == 1) neighbors.push_back({row + 1, col});
    if (col > 0 && maze[row][col - 1] == 1) neighbors.push_back({row, col - 1});
    if (col + 1 < static_cast<int>(maze[0].size()) && maze[row][col + 1] == 1) neighbors.push_back({row, col + 1});
    return neighbors;
}

/**
 * @brief Use backtracking to search for a path through the maze.
 * @param maze const vector<vector<int>>& The maze value used by this function.
 * @param start pair<int, int> The start value used by this function.
 * @param end pair<int, int> The end value used by this function.
 * @param path vector<pair<int, int>>& The current path built by the algorithm.
 * @return bool True when the required condition is satisfied, otherwise false.
 */
bool find_path(const vector<vector<int>>& maze, pair<int, int> start, pair<int, int> end,
               vector<pair<int, int>>& path) {
    path.push_back(start);
    if (start == end) {
        return true;
    }
    for (auto neighbor : get_neighbors(maze, start)) {
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
 * @brief Merge two sorted halves into a single sorted result.
 * @param values vector<int>& The vector of values processed by the function.
 * @param left int The left-side data or left boundary used by the algorithm.
 * @param mid int The middle index used to split the current range.
 * @param right int The right-side data or right boundary used by the algorithm.
 * @return void This function updates data or prints results and does not return a value.
 */
void merge(vector<int>& values, int left, int mid, int right) {
    vector<int> merged;
    int i = left;
    int j = mid + 1;
    while (i <= mid && j <= right) {
        if (values[i] <= values[j]) {
            merged.push_back(values[i++]);
        } else {
            merged.push_back(values[j++]);
        }
    }
    while (i <= mid) merged.push_back(values[i++]);
    while (j <= right) merged.push_back(values[j++]);
    copy(merged.begin(), merged.end(), values.begin() + left);
}

/**
 * @brief Sort the list using merge sort.
 * @param values vector<int>& The vector of values processed by the function.
 * @param left int The left-side data or left boundary used by the algorithm.
 * @param right int The right-side data or right boundary used by the algorithm.
 * @return void This function updates data or prints results and does not return a value.
 */
void merge_sort(vector<int>& values, int left, int right) {
    if (left >= right) return;
    int mid = (left + right) / 2;
    merge_sort(values, left, mid);
    merge_sort(values, mid + 1, right);
    merge(values, left, mid, right);
}

/**
 * @brief Place the pivot in its correct quick-sort position and return that index.
 * @param values vector<int>& The vector of values processed by the function.
 * @param left int The left-side data or left boundary used by the algorithm.
 * @param right int The right-side data or right boundary used by the algorithm.
 * @return int The integer result produced by the algorithm.
 */
int partition(vector<int>& values, int left, int right) {
    int pivot = values[right];
    int smaller = left - 1;
    for (int index = left; index < right; ++index) {
        if (values[index] < pivot) {
            ++smaller;
            swap(values[smaller], values[index]);
        }
    }
    swap(values[smaller + 1], values[right]);
    return smaller + 1;
}

/**
 * @brief Sort the list using quick sort.
 * @param values vector<int>& The vector of values processed by the function.
 * @param left int The left-side data or left boundary used by the algorithm.
 * @param right int The right-side data or right boundary used by the algorithm.
 * @return void This function updates data or prints results and does not return a value.
 */
void quick_sort(vector<int>& values, int left, int right) {
    if (left >= right) return;
    int pivot_index = partition(values, left, right);
    quick_sort(values, left, pivot_index - 1);
    quick_sort(values, pivot_index + 1, right);
}

/**
 * @brief Search for the best travelling-salesperson tour using backtracking.
 * @param distances const vector<vector<int>>& The distances value used by this function.
 * @param current_city int The current_city value used by this function.
 * @param visited vector<bool>& The flags that mark which states are already visited.
 * @param path vector<int>& The current path built by the algorithm.
 * @param current_distance int The current_distance value used by this function.
 * @param best_path vector<int>& The best_path value used by this function.
 * @param best_distance int& The best_distance value used by this function.
 * @return void This function updates data or prints results and does not return a value.
 */
void tsp_backtrack(const vector<vector<int>>& distances, int current_city, vector<bool>& visited,
                   vector<int>& path, int current_distance, vector<int>& best_path, int& best_distance) {
    path.push_back(current_city);
    visited[current_city] = true;

    if (path.size() == distances.size()) {
        int tour_distance = current_distance + distances[current_city][0];
        if (tour_distance < best_distance) {
            best_distance = tour_distance;
            best_path = path;
        }
    } else {
        for (int neighbor = 0; neighbor < static_cast<int>(distances.size()); ++neighbor) {
            if (!visited[neighbor]) {
                tsp_backtrack(distances, neighbor, visited, path,
                              current_distance + distances[current_city][neighbor],
                              best_path, best_distance);
            }
        }
    }

    visited[current_city] = false;
    path.pop_back();
}

/**
 * @brief Return the total distance of one travelling-salesperson tour.
 * @param distances const vector<vector<int>>& The distances value used by this function.
 * @param path const vector<int>& The current path built by the algorithm.
 * @return int The integer result produced by the algorithm.
 */
int path_distance(const vector<vector<int>>& distances, const vector<int>& path) {
    int total = 0;
    for (size_t i = 1; i < path.size(); ++i) {
        total += distances[path[i - 1]][path[i]];
    }
    total += distances[path.back()][path.front()];
    return total;
}

template <typename T>
/**
 * @brief Print the vector in a beginner-friendly format.
 * @param values const vector<T>& The vector of values processed by the function.
 * @return void This function updates data or prints results and does not return a value.
 */
void print_vector(const vector<T>& values) {
    cout << '[';
    for (size_t i = 0; i < values.size(); ++i) {
        cout << values[i];
        if (i + 1 != values.size()) cout << ", ";
    }
    cout << ']';
}

/**
 * @brief Run the small demonstration for this teaching example.
 * @return int The integer result produced by the algorithm.
 */
int main() {
    vector<vector<int>> adjacency_matrix = {{0, 10, 15, 20}, {10, 0, 35, 25}, {15, 35, 0, 30}, {20, 25, 30, 0}};
    cout << "Weighted adjacency matrix:\n";
    for (const auto& row : adjacency_matrix) {
        print_vector(row);
        cout << '\n';
    }
    cout << '\n';

    vector<vector<int>> maze = {{1, 1, 1, 0, 1}, {1, 0, 1, 0, 1}, {1, 0, 1, 1, 1}, {1, 0, 0, 0, 1}, {1, 1, 1, 1, 1}};
    vector<pair<int, int>> path;
    if (find_path(maze, {0, 0}, {4, 4}, path)) {
        cout << "Path through the maze: ";
        for (auto [row, col] : path) cout << '(' << row << ", " << col << ") ";
        cout << "\n\n";
    }

    vector<int> merge_values = {38, 27, 43, 3, 9, 82, 10};
    merge_sort(merge_values, 0, static_cast<int>(merge_values.size()) - 1);
    cout << "Merge sort result: ";
    print_vector(merge_values);
    cout << '\n';

    vector<int> quick_values = {10, 7, 8, 9, 1, 5};
    quick_sort(quick_values, 0, static_cast<int>(quick_values.size()) - 1);
    cout << "Quick sort result: ";
    print_vector(quick_values);
    cout << "\n\n";

    vector<bool> visited(adjacency_matrix.size(), false);
    vector<int> current_path;
    vector<int> best_path;
    int best_distance = INT_MAX;
    tsp_backtrack(adjacency_matrix, 0, visited, current_path, 0, best_path, best_distance);
    cout << "Best TSP path by backtracking: ";
    print_vector(best_path);
    cout << " with distance " << best_distance << '\n';

    vector<int> permutation_path = {0, 1, 2, 3};
    int best_permutation_distance = INT_MAX;
    vector<int> best_permutation_path;
    do {
        int distance = path_distance(adjacency_matrix, permutation_path);
        if (distance < best_permutation_distance) {
            best_permutation_distance = distance;
            best_permutation_path = permutation_path;
        }
    } while (next_permutation(permutation_path.begin() + 1, permutation_path.end()));

    cout << "Best TSP path by permutations: ";
    print_vector(best_permutation_path);
    cout << " with distance " << best_permutation_distance << '\n';
    return 0;
}
