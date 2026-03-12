/**
 * @file bubble-sort.cpp
 * @brief C++ version of the week 5 bubble-sort lecture example.
 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Sort the list in ascending order using bubble sort.
 * @param array vector<int>& List of integers to sort in place.
 * @return void This function updates array in place and does not return a value.
 */
void bubbleSort(vector<int>& array) {
    for (size_t pass_number = 0; pass_number < array.size(); ++pass_number) {
        bool swapped = false;
        for (size_t index = 0; index + 1 < array.size() - pass_number; ++index) {
            if (array[index] > array[index + 1]) {
                swap(array[index], array[index + 1]);
                swapped = true;
            }
        }
        for (int value : array) {
            cout << value << ' ';
        }
        cout << '\n';
        if (!swapped) {
            break;
        }
    }
}

/**
 * @brief Run the bubble-sort lecture example.
 * @return int Exit status code returned to the operating system.
 */
int main() {
    vector<int> data = {6, 5, 3, 1, 8, 7, 2, 4};
    bubbleSort(data);
    return 0;
}
