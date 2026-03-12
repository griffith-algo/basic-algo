/**
 * @file merge-sort.cpp
 * @brief C++ version of the week 5 merge-sort lecture example.
 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Merge two sorted lists into one sorted list.
 * @param left_half const vector<int>& Sorted left half.
 * @param right_half const vector<int>& Sorted right half.
 * @return vector<int> Merged list in ascending order.
 */
vector<int> merge(const vector<int>& left_half, const vector<int>& right_half) {
    vector<int> merged;
    size_t left_index = 0;
    size_t right_index = 0;

    while (left_index < left_half.size() && right_index < right_half.size()) {
        if (left_half[left_index] <= right_half[right_index]) {
            merged.push_back(left_half[left_index++]);
        } else {
            merged.push_back(right_half[right_index++]);
        }
    }

    merged.insert(merged.end(), left_half.begin() + static_cast<long>(left_index), left_half.end());
    merged.insert(merged.end(), right_half.begin() + static_cast<long>(right_index), right_half.end());
    return merged;
}

/**
 * @brief Sort the list in ascending order using merge sort.
 * @param array const vector<int>& Input list of integers.
 * @return vector<int> Sorted copy of array.
 */
vector<int> mergeSort(const vector<int>& array) {
    if (array.size() <= 1) {
        return array;
    }

    size_t middle = array.size() / 2;
    vector<int> left_half(array.begin(), array.begin() + static_cast<long>(middle));
    vector<int> right_half(array.begin() + static_cast<long>(middle), array.end());
    vector<int> merged = merge(mergeSort(left_half), mergeSort(right_half));

    for (int value : merged) {
        cout << value << ' ';
    }
    cout << '\n';
    return merged;
}

/**
 * @brief Run the merge-sort lecture example.
 * @return int Exit status code returned to the operating system.
 */
int main() {
    vector<int> data = {6, 5, 3, 1, 8, 7, 2, 4};
    vector<int> sorted = mergeSort(data);
    cout << "Sorted array: ";
    for (int value : sorted) {
        cout << value << ' ';
    }
    cout << '\n';
    return 0;
}
