#include <iostream>
#include <utility>
#include <vector>

using namespace std;

/**
 * @brief Restore the heap property for the subtree rooted at the given index.
 * @param values vector<int>& The vector of values processed by the function.
 * @param heap_size int The heap_size value used by this function.
 * @param root int The root node of the current tree.
 * @return void This function updates data or prints results and does not return a value.
 */
void heapify(vector<int>& values, int heap_size, int root) {
    int largest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if (left < heap_size && values[left] > values[largest]) largest = left;
    if (right < heap_size && values[right] > values[largest]) largest = right;

    if (largest != root) {
        swap(values[root], values[largest]);
        heapify(values, heap_size, largest);
    }
}

/**
 * @brief Sort the list in ascending order using heap sort.
 * @param values vector<int>& The vector of values processed by the function.
 * @return void This function updates data or prints results and does not return a value.
 */
void heapSort(vector<int>& values) {
    for (int index = static_cast<int>(values.size()) / 2 - 1; index >= 0; --index) {
        heapify(values, static_cast<int>(values.size()), index);
    }
    for (int end = static_cast<int>(values.size()) - 1; end > 0; --end) {
        swap(values[0], values[end]);
        heapify(values, end, 0);
    }
}

/**
 * @brief Run the small demonstration for this teaching example.
 * @return int The integer result produced by the algorithm.
 */
int main() {
    vector<int> data = {1, 12, 9, 5, 6, 10};
    heapSort(data);
    for (int value : data) cout << value << ' ';
    cout << '\n';
    return 0;
}
