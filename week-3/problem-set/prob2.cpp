/**
 * @file prob2.cpp
 * @brief C++ version of the step-by-step selection-sort example.
 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Sort the list in ascending order using selection sort.
 * @param arr vector<int>& List of integers sorted in place.
 * @return vector<int> Copy of the sorted list after the algorithm finishes.
 */
vector<int> selection_sort(vector<int>& arr) {
    for (size_t i = 0; i < arr.size(); ++i) {
        size_t min_index = i;
        for (size_t j = i + 1; j < arr.size(); ++j) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        swap(arr[i], arr[min_index]);
        cout << "Step " << (i + 1) << ": ";
        for (int value : arr) {
            cout << value << ' ';
        }
        cout << '\n';
    }
    return arr;
}

/**
 * @brief Run the selection-sort demonstration.
 * @return int Exit status code returned to the operating system.
 */
int main() {
    vector<int> arr = {89, 45, 68, 90, 29, 34, 17};
    cout << "Original array: ";
    for (int value : arr) {
        cout << value << ' ';
    }
    cout << '\n';
    selection_sort(arr);
    cout << "Sorted array: ";
    for (int value : arr) {
        cout << value << ' ';
    }
    cout << '\n';
    return 0;
}
