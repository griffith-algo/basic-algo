#include <iostream>
#include <utility>
#include <vector>

using namespace std;

/**
 * @brief Place the pivot in its correct quick-sort position and return that index.
 * @param values vector<int>& The vector of values processed by the function.
 * @param low int The lower index or lower boundary of the current range.
 * @param high int The upper index or upper boundary of the current range.
 * @return int The integer result produced by the algorithm.
 */
int partition(vector<int>& values, int low, int high) {
    int pivot = values[high];
    int smaller = low - 1;
    for (int index = low; index < high; ++index) {
        if (values[index] <= pivot) {
            ++smaller;
            swap(values[smaller], values[index]);
        }
    }
    swap(values[smaller + 1], values[high]);
    return smaller + 1;
}

/**
 * @brief Sort the list in ascending order using quick sort.
 * @param values vector<int>& The vector of values processed by the function.
 * @param low int The lower index or lower boundary of the current range.
 * @param high int The upper index or upper boundary of the current range.
 * @return void This function updates data or prints results and does not return a value.
 */
void quickSort(vector<int>& values, int low, int high) {
    if (low >= high) return;
    int pivot_index = partition(values, low, high);
    quickSort(values, low, pivot_index - 1);
    quickSort(values, pivot_index + 1, high);
}

/**
 * @brief Run the small demonstration for this teaching example.
 * @return int The integer result produced by the algorithm.
 */
int main() {
    vector<int> data = {8, 7, 2, 1, 0, 9, 6};
    quickSort(data, 0, static_cast<int>(data.size()) - 1);
    for (int value : data) cout << value << ' ';
    cout << '\n';
    return 0;
}
