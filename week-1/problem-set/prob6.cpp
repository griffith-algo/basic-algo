/**
 * @file prob6.cpp
 * @brief C++ version of the comparison-counting sort example.
 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Sort the list by counting how many values are smaller than each element.
 * @param values const vector<int>& Input list of integers to sort.
 * @return vector<int> Sorted list produced by the comparison-counting method.
 */
vector<int> comparison_counting_sort(const vector<int>& values) {
    int n = static_cast<int>(values.size());
    vector<int> count(n, 0);
    vector<int> sorted(n, 0);

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (values[i] < values[j]) {
                ++count[j];
            } else {
                ++count[i];
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        sorted[count[i]] = values[i];
    }

    return sorted;
}

/**
 * @brief Print a vector of integers in bracket form.
 * @param values const vector<int>& Vector to print. Each element has type int.
 * @return void This helper only prints data and does not return a value.
 */
void print_vector(const vector<int>& values) {
    cout << '[';
    for (size_t index = 0; index < values.size(); ++index) {
        cout << values[index];
        if (index + 1 != values.size()) {
            cout << ", ";
        }
    }
    cout << ']';
}

/**
 * @brief Run the comparison-counting-sort demonstration.
 * @return int Exit status code returned to the operating system.
 */
int main() {
    vector<int> values = {60, 35, 81, 98, 14, 47};
    vector<int> sorted = comparison_counting_sort(values);
    print_vector(sorted);
    cout << '\n';
    return 0;
}
