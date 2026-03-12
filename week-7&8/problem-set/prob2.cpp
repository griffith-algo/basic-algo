/**
 * @file prob2.cpp
 * @brief C++ version of the two-way comparison binary-search example.
 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Search a sorted list using one equality test and one ordering test per loop.
 * @param arr const vector<int>& Sorted list of integers.
 * @param target int Value to search for.
 * @return int Index of target when it is found, otherwise -1.
 */
int two_way_comparison_binary_search(const vector<int>& arr, int target) {
    int left = 0;
    int right = static_cast<int>(arr.size()) - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] <= target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

/**
 * @brief Run the binary-search demonstration.
 * @return int Exit status code returned to the operating system.
 */
int main() {
    vector<int> arr = {3, 14, 27, 31, 39, 42, 55, 70, 74, 81, 85, 93, 98};
    int target = 3;
    int result = two_way_comparison_binary_search(arr, target);

    if (result != -1) {
        cout << "Element " << target << " found at index " << result << ".\n";
    } else {
        cout << "Element " << target << " not found in the array.\n";
    }
    return 0;
}
