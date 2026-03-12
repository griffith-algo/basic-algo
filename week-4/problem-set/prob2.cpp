/**
 * @file prob2.cpp
 * @brief C++ version of the divide-and-conquer minimum/maximum example.
 */

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

/**
 * @brief Return the minimum and maximum values in a range using divide and conquer.
 * @param arr const vector<int>& Input list of integers.
 * @param low int Left boundary of the current recursive range.
 * @param high int Right boundary of the current recursive range.
 * @return pair<int, int> Pair containing (minimum, maximum) for arr[low..high].
 */
pair<int, int> find_min_max(const vector<int>& arr, int low, int high) {
    if (low == high) {
        return {arr[low], arr[low]};
    }
    if (high == low + 1) {
        return {min(arr[low], arr[high]), max(arr[low], arr[high])};
    }

    int mid = (low + high) / 2;
    pair<int, int> left = find_min_max(arr, low, mid);
    pair<int, int> right = find_min_max(arr, mid + 1, high);
    return {min(left.first, right.first), max(left.second, right.second)};
}

/**
 * @brief Run the minimum/maximum demonstration.
 * @return int Exit status code returned to the operating system.
 */
int main() {
    vector<int> arr = {3, 7, 1, 8, 2, 5};
    pair<int, int> result = find_min_max(arr, 0, static_cast<int>(arr.size()) - 1);
    cout << "Array: ";
    for (int value : arr) {
        cout << value << ' ';
    }
    cout << "\nMinimum: " << result.first << "\nMaximum: " << result.second << '\n';
    return 0;
}
