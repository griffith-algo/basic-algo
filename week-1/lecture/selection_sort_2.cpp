/**
 * @file selection_sort_2.cpp
 * @brief Console-based C++ equivalent of the Pygame selection-sort example.
 */

#include <chrono>
#include <iostream>
#include <thread>
#include <vector>

using namespace std;

/**
 * @brief Print the array and highlight one index with brackets.
 * @param values const vector<int>& List of integers currently being sorted.
 * @param highlighted_index int Index to highlight. Use -1 when no value should be highlighted.
 * @return void This helper only prints data and does not return a value.
 */
void draw_array(const vector<int>& values, int highlighted_index = -1) {
    for (size_t index = 0; index < values.size(); ++index) {
        if (static_cast<int>(index) == highlighted_index) {
            cout << '[' << values[index] << "] ";
        } else {
            cout << values[index] << ' ';
        }
    }
    cout << '\n';
}

/**
 * @brief Sort a list in ascending order with selection sort and show each pass.
 * @param values vector<int>& List of integers that the algorithm reorders in place.
 * @return vector<int> Copy of the sorted list so the caller can inspect the final state.
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
        draw_array(values, static_cast<int>(i));
        this_thread::sleep_for(chrono::milliseconds(150));
    }
    return values;
}

/**
 * @brief Run the console visualisation of selection sort.
 * @return int Exit status code returned to the operating system.
 */
int main() {
    vector<int> values = {14, 3, 22, 9, 17, 5, 11, 1, 19, 7};
    draw_array(values);
    selection_sort(values);
    draw_array(values);
    return 0;
}
