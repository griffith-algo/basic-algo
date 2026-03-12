/**
 * @file merge_sort.cpp
 * @brief Console-based C++ version of the merge-sort visualisation example.
 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Print the current array state in one row.
 * @param values const vector<int>& List of integers currently being sorted.
 * @return void This helper only prints data and does not return a value.
 */
void print_values(const vector<int>& values) {
    for (int value : values) {
        cout << value << ' ';
    }
    cout << '\n';
}

/**
 * @brief Merge two sorted subarrays into one sorted result.
 * @param values vector<int>& Full list being sorted.
 * @param left int Left boundary of the current merge range.
 * @param mid int Last index of the left half.
 * @param right int Right boundary of the current merge range.
 * @return void This function updates values in place and does not return a value.
 */
void merge(vector<int>& values, int left, int mid, int right) {
    vector<int> merged;
    int left_index = left;
    int right_index = mid + 1;

    while (left_index <= mid && right_index <= right) {
        if (values[left_index] <= values[right_index]) {
            merged.push_back(values[left_index++]);
        } else {
            merged.push_back(values[right_index++]);
        }
    }
    while (left_index <= mid) {
        merged.push_back(values[left_index++]);
    }
    while (right_index <= right) {
        merged.push_back(values[right_index++]);
    }

    for (size_t offset = 0; offset < merged.size(); ++offset) {
        values[left + static_cast<int>(offset)] = merged[offset];
    }
    print_values(values);
}

/**
 * @brief Sort a list with merge sort.
 * @param values vector<int>& List of integers to sort in place.
 * @param left int Left boundary of the current recursive range.
 * @param right int Right boundary of the current recursive range.
 * @return void This function updates values in place and does not return a value.
 */
void merge_sort(vector<int>& values, int left, int right) {
    if (left >= right) {
        return;
    }

    int mid = (left + right) / 2;
    merge_sort(values, left, mid);
    merge_sort(values, mid + 1, right);
    merge(values, left, mid, right);
}

/**
 * @brief Run the merge-sort demonstration.
 * @return int Exit status code returned to the operating system.
 */
int main() {
    vector<int> data = {38, 27, 43, 3, 9, 82, 10, 15, 21, 6, 49, 1, 35, 7, 18};
    print_values(data);
    merge_sort(data, 0, static_cast<int>(data.size()) - 1);
    print_values(data);
    return 0;
}
