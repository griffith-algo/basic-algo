/**
 * @file prob12.cpp
 * @brief C++ version of the heap-printing and heap-check example.
 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Print a heap sideways so the tree shape is easier to see.
 * @param heap const vector<int>& Heap values stored in array form.
 * @param index int Current node index visited by the recursive call.
 * @param indent int Number of spaces printed before the current value.
 * @return void This function only prints data and does not return a value.
 */
void print_heap(const vector<int>& heap, int index = 0, int indent = 0) {
    if (index >= static_cast<int>(heap.size())) {
        return;
    }
    print_heap(heap, 2 * index + 2, indent + 2);
    cout << string(indent, ' ') << heap[index] << '\n';
    print_heap(heap, 2 * index + 1, indent + 2);
}

/**
 * @brief Return true when an array satisfies the min-heap property.
 * @param H const vector<int>& Heap values stored in array form.
 * @return bool True when every parent is less than or equal to its children, otherwise false.
 */
bool is_min_heap(const vector<int>& H) {
    int n = static_cast<int>(H.size());
    for (int i = 1; i <= (n - 1) / 2; ++i) {
        int left_child = 2 * i;
        int right_child = 2 * i + 1;
        if (H[i - 1] > H[left_child - 1] || (right_child <= n && H[i - 1] > H[right_child - 1])) {
            return false;
        }
    }
    return true;
}

/**
 * @brief Return true when an array satisfies the max-heap property.
 * @param H const vector<int>& Heap values stored in array form.
 * @return bool True when every parent is greater than or equal to its children, otherwise false.
 */
bool is_max_heap(const vector<int>& H) {
    int n = static_cast<int>(H.size());
    for (int i = 1; i <= (n - 1) / 2; ++i) {
        int left_child = 2 * i;
        int right_child = 2 * i + 1;
        if (H[i - 1] < H[left_child - 1] || (right_child <= n && H[i - 1] < H[right_child - 1])) {
            return false;
        }
    }
    return true;
}

/**
 * @brief Run the heap demonstrations.
 * @return int Exit status code returned to the operating system.
 */
int main() {
    vector<int> min_heap_array = {1, 2, 3, 4, 5, 6, 7};
    cout << "Min-Heap:\n";
    print_heap(min_heap_array);
    cout << '\n';

    vector<int> max_heap_array = {7, 6, 5, 4, 3, 2, 1};
    cout << "Max-Heap:\n";
    print_heap(max_heap_array);

    cout << boolalpha;
    cout << "Example 1 (Valid max-heap): " << is_max_heap({9, 7, 6, 4, 3, 5, 1}) << '\n';
    cout << "Example 2 (Invalid max-heap): " << is_max_heap({9, 7, 6, 4, 3, 5, 10}) << '\n';
    cout << "Example 3 (Valid max-heap, single element): " << is_max_heap({1}) << '\n';
    cout << "Example 4 (Valid max-heap, sorted in non-ascending order): " << is_max_heap(max_heap_array) << '\n';
    return 0;
}
