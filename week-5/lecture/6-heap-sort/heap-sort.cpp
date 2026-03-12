/**
 * @file heap-sort.cpp
 * @brief C++ version of the week 5 heap-sort lecture example.
 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Restore the heap property for the subtree rooted at a given index.
 * @param arr vector<int>& List of integers arranged as a binary heap in an array.
 * @param n int Number of heap elements currently considered active.
 * @param i int Root index of the subtree that may violate the heap property.
 * @return void This function updates arr in place and does not return a value.
 */
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

/**
 * @brief Sort the list in ascending order using heap sort.
 * @param arr vector<int>& List of integers to sort in place.
 * @return void This function updates arr in place and does not return a value.
 */
void heapSort(vector<int>& arr) {
    int n = static_cast<int>(arr.size());

    for (int i = n / 2; i >= 0; --i) {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i > 0; --i) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

/**
 * @brief Run the heap-sort lecture example.
 * @return int Exit status code returned to the operating system.
 */
int main() {
    vector<int> arr = {1, 12, 9, 5, 6, 10};
    heapSort(arr);
    cout << "Sorted array is\n";
    for (int value : arr) {
        cout << value << ' ';
    }
    cout << '\n';
    return 0;
}
