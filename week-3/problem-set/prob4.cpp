/**
 * @file prob4.cpp
 * @brief C++ version of the bubble-sort early-exit example.
 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Sort the list using bubble sort.
 * @param array vector<int>& List of integers sorted in place.
 * @return vector<int> Copy of the sorted list after the algorithm finishes.
 */
vector<int> bubble_sort(vector<int>& array) {
    int n = static_cast<int>(array.size());

    for (int i = 0; i < n; ++i) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if (array[j] > array[j + 1]) {
                swap(array[j], array[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            cout << "No swaps were needed on this pass, so the list is already sorted.\n";
            break;
        }
    }
    return array;
}

/**
 * @brief Run the bubble-sort demonstration.
 * @return int Exit status code returned to the operating system.
 */
int main() {
    vector<int> my_list = {4, 2, 8, 3, 1, 9, 6, 5, 7};
    cout << "Original list: ";
    for (int value : my_list) {
        cout << value << ' ';
    }
    cout << '\n';
    bubble_sort(my_list);
    cout << "Sorted list: ";
    for (int value : my_list) {
        cout << value << ' ';
    }
    cout << '\n';
    return 0;
}
