/**
 * @file quick-sort.cpp
 * @brief C++ version of the week 5 quick-sort lecture example.
 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Place the pivot in its final quick-sort position.
 * @param array vector<int>& List of integers being sorted in place.
 * @param low int Left boundary of the current partition.
 * @param high int Right boundary of the current partition. The pivot is array[high].
 * @return int Final pivot index after partitioning.
 */
int partition(vector<int>& array, int low, int high) {
    int pivot = array[high];
    int smaller = low - 1;

    for (int index = low; index < high; ++index) {
        if (array[index] <= pivot) {
            ++smaller;
            swap(array[smaller], array[index]);
        }
    }

    swap(array[smaller + 1], array[high]);
    return smaller + 1;
}

/**
 * @brief Sort the list in ascending order using quick sort.
 * @param array vector<int>& List of integers to sort in place.
 * @param low int Left boundary of the current recursive range.
 * @param high int Right boundary of the current recursive range.
 * @return void This function updates array in place and does not return a value.
 */
void quickSort(vector<int>& array, int low, int high) {
    if (low < high) {
        int pivot_index = partition(array, low, high);
        quickSort(array, low, pivot_index - 1);
        quickSort(array, pivot_index + 1, high);
    }
}

/**
 * @brief Run the quick-sort lecture example.
 * @return int Exit status code returned to the operating system.
 */
int main() {
    vector<int> data = {8, 7, 2, 1, 0, 9, 6};
    cout << "Unsorted Array\n";
    for (int value : data) {
        cout << value << ' ';
    }
    cout << '\n';

    quickSort(data, 0, static_cast<int>(data.size()) - 1);

    cout << "Sorted Array in Ascending Order:\n";
    for (int value : data) {
        cout << value << ' ';
    }
    cout << '\n';
    return 0;
}
