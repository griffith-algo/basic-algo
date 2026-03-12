/**
 * @file prob8.cpp
 * @brief C++ version of the max-heap-check example.
 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Return true when an array satisfies the max-heap property.
 * @param H const vector<int>& Heap array that uses index 0 as a dummy value and stores the real heap from index 1.
 * @return bool True when every parent is greater than or equal to its children, otherwise false.
 */
bool is_max_heap(const vector<int>& H) {
    int n = static_cast<int>(H.size()) - 1;
    for (int i = 1; i <= n / 2; ++i) {
        int left_child = 2 * i;
        int right_child = 2 * i + 1;
        if (left_child <= n && H[i] < H[left_child]) {
            return false;
        }
        if (right_child <= n && H[i] < H[right_child]) {
            return false;
        }
    }
    return true;
}

/**
 * @brief Run the max-heap-check demonstration.
 * @return int Exit status code returned to the operating system.
 */
int main() {
    vector<int> heap_example1 = {0, 90, 80, 70, 60, 50, 40, 30, 20, 10};
    vector<int> heap_example2 = {0, 90, 80, 70, 60, 50, 40, 100, 20, 10};
    cout << boolalpha;
    cout << "Example 1 is a max-heap: " << is_max_heap(heap_example1) << '\n';
    cout << "Example 2 is a max-heap: " << is_max_heap(heap_example2) << '\n';
    return 0;
}
