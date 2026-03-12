/**
 * @file quick_sort.cpp
 * @brief Console-based C++ version of the quick-sort visualisation example.
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
 * @brief Place the pivot in its final quick-sort position.
 * @param values vector<int>& List of integers being sorted in place.
 * @param left int Left boundary of the current partition.
 * @param right int Right boundary of the current partition. The pivot is values[right].
 * @return int Final index of the pivot.
 */
int partition(vector<int>& values, int left, int right) {
    int pivot = values[right];
    int smaller = left - 1;

    for (int index = left; index < right; ++index) {
        if (values[index] < pivot) {
            ++smaller;
            swap(values[smaller], values[index]);
            print_values(values);
        }
    }
    swap(values[smaller + 1], values[right]);
    print_values(values);
    return smaller + 1;
}

/**
 * @brief Sort a list with quick sort.
 * @param values vector<int>& List of integers to sort in place.
 * @param left int Left boundary of the current recursive range.
 * @param right int Right boundary of the current recursive range.
 * @return void This function updates values in place and does not return a value.
 */
void quick_sort(vector<int>& values, int left, int right) {
    if (left < right) {
        int pivot_index = partition(values, left, right);
        quick_sort(values, left, pivot_index - 1);
        quick_sort(values, pivot_index + 1, right);
    }
}

/**
 * @brief Run the quick-sort demonstration.
 * @return int Exit status code returned to the operating system.
 */
int main() {
    vector<int> data = {19, 4, 27, 8, 11, 3, 25, 14, 6, 17, 1, 23, 9, 30, 12};
    print_values(data);
    quick_sort(data, 0, static_cast<int>(data.size()) - 1);
    print_values(data);
    return 0;
}
