/**
 * @file prob5.cpp
 * @brief C++ version of the divide-and-conquer maximum-position example.
 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Return the index of the largest value using divide and conquer.
 * @param arr const vector<int>& Input list of integers.
 * @param left int Left boundary of the current recursive range.
 * @param right int Right boundary of the current recursive range.
 * @return int Index of the largest value inside arr[left..right].
 */
int find_largest_position(const vector<int>& arr, int left, int right) {
    if (left == right) {
        return left;
    }

    int mid = (left + right) / 2;
    int left_max_position = find_largest_position(arr, left, mid);
    int right_max_position = find_largest_position(arr, mid + 1, right);
    return arr[left_max_position] >= arr[right_max_position] ? left_max_position : right_max_position;
}

/**
 * @brief Run the maximum-position demonstration.
 * @return int Exit status code returned to the operating system.
 */
int main() {
    vector<int> arr = {3, 5, 4, 6, 2};
    cout << "The largest element in the array is at position "
         << find_largest_position(arr, 0, static_cast<int>(arr.size()) - 1) << '\n';
    return 0;
}
