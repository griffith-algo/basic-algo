/**
 * @file prob7.cpp
 * @brief C++ version of the stack-sorting example.
 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Sort a stack so the smallest value ends up on top.
 * @param values vector<int> Stack stored as a vector where the back element is the top.
 * @return vector<int> Sorted stack.
 */
vector<int> sort_stack(vector<int> values) {
    vector<int> temp;
    while (!values.empty()) {
        int x = values.back();
        values.pop_back();
        while (!temp.empty() && temp.back() < x) {
            values.push_back(temp.back());
            temp.pop_back();
        }
        temp.push_back(x);
    }
    while (!temp.empty()) {
        values.push_back(temp.back());
        temp.pop_back();
    }
    return values;
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
 * @brief Run the stack-sorting demonstration.
 * @return int Exit status code returned to the operating system.
 */
int main() {
    vector<int> values = {1, 3, 2, 5, 4};
    print_vector(sort_stack(values));
    cout << '\n';
    return 0;
}
