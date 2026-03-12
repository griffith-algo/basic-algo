/**
 * @file selection-sort.cpp
 * @brief C++ version of the week 5 selection-sort lecture example.
 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Sort the list in ascending order using selection sort.
 * @param array vector<int>& List of integers to sort in place.
 * @param size size_t Number of elements from array to process.
 * @return void This function updates array in place and does not return a value.
 */
void selectionSort(vector<int>& array, size_t size) {
    for (size_t step = 0; step < size; ++step) {
        size_t min_idx = step;
        for (size_t i = step + 1; i < size; ++i) {
            if (array[i] < array[min_idx]) {
                min_idx = i;
            }
        }
        swap(array[step], array[min_idx]);
        for (int value : array) {
            cout << value << ' ';
        }
        cout << '\n';
    }
}

/**
 * @brief Run the selection-sort lecture example.
 * @return int Exit status code returned to the operating system.
 */
int main() {
    vector<int> data = {-2, 45, 0, 11, -9, 3};
    selectionSort(data, data.size());
    return 0;
}
