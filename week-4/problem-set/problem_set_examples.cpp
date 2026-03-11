#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

/**
 * @brief Return both the minimum and the maximum values.
 * @param values const vector<int>& The vector of values processed by the function.
 * @param low int The lower index or lower boundary of the current range.
 * @param high int The upper index or upper boundary of the current range.
 * @return pair<int, int> The pair of values produced by the algorithm.
 */
pair<int, int> find_min_max(const vector<int>& values, int low, int high) {
    if (low == high) {
        return {values[low], values[low]};
    }
    if (high == low + 1) {
        return {min(values[low], values[high]), max(values[low], values[high])};
    }
    int mid = (low + high) / 2;
    auto left = find_min_max(values, low, mid);
    auto right = find_min_max(values, mid + 1, high);
    return {min(left.first, right.first), max(left.second, right.second)};
}

/**
 * @brief Compute the recurrence value with memoization.
 * @param n int The size value or number of recursive steps used by the function.
 * @param memo vector<int>& The memoization table used to store earlier results.
 * @return int The integer result produced by the algorithm.
 */
int F(int n, vector<int>& memo) {
    if (n < 3) {
        return 1;
    }
    if (memo[n] == -1) {
        memo[n] = F(n - 1, memo) + F(n - 2, memo);
    }
    return memo[n];
}

/**
 * @brief Return 2 raised to the power n using recursion.
 * @param n int The size value or number of recursive steps used by the function.
 * @return int The integer result produced by the algorithm.
 */
int power_of_two(int n) {
    if (n == 0) {
        return 1;
    }
    return 2 * power_of_two(n - 1);
}

/**
 * @brief Run the small demonstration for this teaching example.
 * @return int The integer result produced by the algorithm.
 */
int main() {
    vector<int> values = {3, 7, 1, 8, 2, 5};
    auto [minimum, maximum] = find_min_max(values, 0, static_cast<int>(values.size()) - 1);
    cout << "Minimum: " << minimum << ", maximum: " << maximum << '\n';

    int n = 10;
    vector<int> memo(n + 1, -1);
    cout << "F(10) = " << F(n, memo) << '\n';
    cout << "2^5 = " << power_of_two(5) << '\n';
    return 0;
}
