/**
 * @file insertion-sort.cpp
 * @brief C++ version of the week 5 insertion-sort lecture example.
 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Sort the list in ascending order using insertion sort.
 * @param array vector<int>& List of integers to sort in place.
 * @return void This function updates array in place and does not return a value.
 */
void insertionSort(vector<int>& array) {
    for (size_t step = 1; step < array.size(); ++step) {
        int key = array[step];
        int j = static_cast<int>(step) - 1;

        while (j >= 0 && key < array[j]) {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = key;

        for (int value : array) {
            cout << value << ' ';
        }
        cout << '\n';
    }
}

/**
 * @brief Run the insertion-sort lecture example.
 * @return int Exit status code returned to the operating system.
 */
int main() {
    vector<int> data = {6, 5, 3, 1, 8, 7, 2, 4};
    insertionSort(data);
    return 0;
}
