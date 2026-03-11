#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Return true when the heap satisfies the max-heap property.
 * @param heap_values const vector<int>& The heap_values value used by this function.
 * @return bool True when the required condition is satisfied, otherwise false.
 */
bool is_max_heap(const vector<int>& heap_values) {
    for (size_t parent = 1; parent <= heap_values.size() / 2; ++parent) {
        size_t left_child = 2 * parent;
        size_t right_child = 2 * parent + 1;
        if (left_child < heap_values.size() && heap_values[parent] < heap_values[left_child]) return false;
        if (right_child < heap_values.size() && heap_values[parent] < heap_values[right_child]) return false;
    }
    return true;
}

/**
 * @brief Run the small demonstration for this teaching example.
 * @return int The integer result produced by the algorithm.
 */
int main() {
    vector<int> heap1 = {0, 90, 80, 70, 60, 50, 40, 30, 20, 10};
    vector<int> heap2 = {0, 90, 80, 70, 60, 50, 40, 100, 20, 10};
    cout << boolalpha;
    cout << "Example 1 is a max-heap: " << is_max_heap(heap1) << '\n';
    cout << "Example 2 is a max-heap: " << is_max_heap(heap2) << '\n';
    return 0;
}
