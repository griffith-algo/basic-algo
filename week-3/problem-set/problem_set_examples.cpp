#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

/**
 * @brief Identify the network topology from the adjacency matrix.
 * @param matrix const vector<vector<int>>& The matrix or table processed by the function.
 * @return string The string produced by the algorithm.
 */
string determine_topology(const vector<vector<int>>& matrix) {
    int n = static_cast<int>(matrix.size());
    bool is_ring = true;
    for (int i = 0; i < n; ++i) {
        int degree = count(matrix[i].begin(), matrix[i].end(), 1);
        if (degree != 2) {
            is_ring = false;
        }
    }
    if (is_ring) return "Ring Topology";

    bool is_star = true;
    int centers = 0;
    for (int i = 0; i < n; ++i) {
        int degree = count(matrix[i].begin(), matrix[i].end(), 1);
        if (degree == n - 1) ++centers;
        else if (degree != 1) is_star = false;
    }
    if (is_star && centers == 1) return "Star Topology";

    bool is_mesh = true;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j && matrix[i][j] == 0) is_mesh = false;
        }
    }
    if (is_mesh) return "Fully Connected Mesh Topology";
    return "Unknown Topology";
}

/**
 * @brief Sort the list in ascending order using selection sort.
 * @param values vector<int>& The vector of values processed by the function.
 * @return void This function updates data or prints results and does not return a value.
 */
void selection_sort(vector<int>& values) {
    for (size_t i = 0; i < values.size(); ++i) {
        size_t min_index = i;
        for (size_t j = i + 1; j < values.size(); ++j) {
            if (values[j] < values[min_index]) min_index = j;
        }
        swap(values[i], values[min_index]);
        cout << "Step " << (i + 1) << ": ";
        for (int value : values) cout << value << ' ';
        cout << '\n';
    }
}

/**
 * @brief Group identical disks together by swapping neighbours.
 * @param disks vector<char> The disks value used by this function.
 * @return vector<char> The vector produced by the algorithm.
 */
vector<char> alternating_disks(vector<char> disks) {
    bool swapped = true;
    while (swapped) {
        swapped = false;
        for (size_t i = 0; i + 1 < disks.size(); ++i) {
            if (disks[i] == 'D' && disks[i + 1] == 'L') {
                swap(disks[i], disks[i + 1]);
                swapped = true;
            }
        }
    }
    return disks;
}

/**
 * @brief Sort the list in ascending order using bubble sort.
 * @param values vector<int> The vector of values processed by the function.
 * @return vector<int> The vector produced by the algorithm.
 */
vector<int> bubble_sort(vector<int> values) {
    for (size_t pass = 0; pass < values.size(); ++pass) {
        bool swapped = false;
        for (size_t i = 0; i + 1 < values.size() - pass; ++i) {
            if (values[i] > values[i + 1]) {
                swap(values[i], values[i + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
    return values;
}

/**
 * @brief Return the index of the largest value using divide and conquer.
 * @param values const vector<int>& The vector of values processed by the function.
 * @param left int The left-side data or left boundary used by the algorithm.
 * @param right int The right-side data or right boundary used by the algorithm.
 * @return int The integer result produced by the algorithm.
 */
int find_largest_position(const vector<int>& values, int left, int right) {
    if (left == right) return left;
    int mid = (left + right) / 2;
    int left_pos = find_largest_position(values, left, mid);
    int right_pos = find_largest_position(values, mid + 1, right);
    return values[left_pos] >= values[right_pos] ? left_pos : right_pos;
}

/**
 * @brief Count the number of ways to make the target sum.
 * @param coins const vector<int>& The coins value used by this function.
 * @param total int The total value used by this function.
 * @return int The integer result produced by the algorithm.
 */
int count_dynamic_programming(const vector<int>& coins, int total) {
    vector<vector<int>> table(coins.size() + 1, vector<int>(total + 1, 0));
    for (size_t row = 0; row < table.size(); ++row) table[row][0] = 1;
    for (size_t i = 1; i <= coins.size(); ++i) {
        for (int amount = 1; amount <= total; ++amount) {
            int without_coin = table[i - 1][amount];
            int with_coin = coins[i - 1] <= amount ? table[i][amount - coins[i - 1]] : 0;
            table[i][amount] = without_coin + with_coin;
        }
    }
    return table[coins.size()][total];
}

/**
 * @brief Choose coins greedily from largest denomination to smallest.
 * @param total int The total value used by this function.
 * @param denominations const vector<int>& The denominations value used by this function.
 * @return map<int, int, greater<int>> The value produced by this function.
 */
map<int, int, greater<int>> greedy_change_with_denominations(int total, const vector<int>& denominations) {
    map<int, int, greater<int>> result;
    for (int coin : denominations) {
        while (total >= coin) {
            total -= coin;
            ++result[coin];
        }
    }
    return result;
}

/**
 * @brief Order the jobs to minimise the total completion time.
 * @param jobs vector<pair<int, int>> The jobs value used by this function.
 * @return int The integer result produced by the algorithm.
 */
int schedule_jobs(vector<pair<int, int>> jobs) {
    sort(jobs.begin(), jobs.end(), [](const auto& left, const auto& right) {
        return left.second < right.second;
    });
    int total_time = 0;
    int elapsed = 0;
    for (const auto& job : jobs) {
        elapsed += job.second;
        total_time += elapsed;
    }
    return total_time;
}

/**
 * @brief Return the maximum value collectable from non-adjacent coins.
 * @param coins const vector<int>& The coins value used by this function.
 * @return int The integer result produced by the algorithm.
 */
int max_coin_row(const vector<int>& coins) {
    vector<int> best(coins.size() + 1, 0);
    best[1] = coins[0];
    for (size_t i = 2; i <= coins.size(); ++i) {
        best[i] = max(best[i - 1], coins[i - 1] + best[i - 2]);
    }
    return best.back();
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
    vector<vector<int>> ring = {{0, 1, 0, 1}, {1, 0, 1, 0}, {0, 1, 0, 1}, {1, 0, 1, 0}};
    cout << determine_topology(ring) << "\n\n";

    vector<int> selection_values = {89, 45, 68, 90, 29, 34, 17};
    selection_sort(selection_values);
    cout << '\n';

    print_vector(alternating_disks({'D', 'L', 'D', 'L', 'D', 'L'}));
    cout << '\n';
    print_vector(bubble_sort({4, 2, 8, 3, 1, 9, 6, 5, 7}));
    cout << '\n';

    vector<int> values = {3, 5, 4, 6, 2};
    cout << "Largest value index: " << find_largest_position(values, 0, static_cast<int>(values.size()) - 1) << '\n';
    cout << "Coin-change count: " << count_dynamic_programming({1, 2, 3}, 4) << '\n';

    auto greedy = greedy_change_with_denominations(11, {9, 3, 2});
    cout << "Greedy change: ";
    for (const auto& [coin, count] : greedy) cout << coin << "->" << count << ' ';
    cout << '\n';

    cout << "Job scheduling total time: " << schedule_jobs({{1, 5}, {2, 3}, {3, 7}, {4, 2}}) << '\n';
    cout << "Max coin row: " << max_coin_row({5, 1, 2, 10, 6}) << '\n';
    return 0;
}
