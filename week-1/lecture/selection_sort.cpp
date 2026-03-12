/**
 * @file selection_sort.cpp
 * @brief Console-based C++ version of the selection-sort visualisation example.
 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Print the values in one row.
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
 * @brief Sort a list in ascending order with selection sort.
 * @param values vector<int>& List of integers that the algorithm reorders in place.
 * @return vector<int> Reference-style copy of the now sorted list, returned for easy printing.
 */
vector<int> selection_sort(vector<int>& values) {
    for (size_t i = 0; i < values.size(); ++i) {
        size_t min_index = i;
        for (size_t j = i + 1; j < values.size(); ++j) {
            if (values[j] < values[min_index]) {
                min_index = j;
            }
        }
        swap(values[i], values[min_index]);
        print_values(values);
    }
    return values;
}

/**
 * @brief Run the selection-sort demonstration.
 * @return int Exit status code returned to the operating system.
 */
int main() {
    vector<int> values = {19, 7, 42, 3, 11, 25, 8, 31, 16, 5};
    cout << "Unsorted array: ";
    print_values(values);
    selection_sort(values);
    cout << "Sorted array: ";
    print_values(values);
    return 0;
}
