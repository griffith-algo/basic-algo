/**
 * @file prob6.cpp
 * @brief C++ version of the stack-reversal examples.
 */

#include <deque>
#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Reverse a stack using two temporary stacks.
 * @param values vector<int> Stack stored as a vector where the back element is the top.
 * @return vector<int> Reversed stack.
 */
vector<int> reverse_stack_with_two_stacks(vector<int> values) {
    vector<int> first;
    vector<int> second;
    while (!values.empty()) {
        first.push_back(values.back());
        values.pop_back();
    }
    while (!first.empty()) {
        second.push_back(first.back());
        first.pop_back();
    }
    while (!second.empty()) {
        values.push_back(second.back());
        second.pop_back();
    }
    return values;
}

/**
 * @brief Reverse a stack using one queue.
 * @param values vector<int> Stack stored as a vector where the back element is the top.
 * @return vector<int> Reversed stack.
 */
vector<int> reverse_stack_with_one_queue(vector<int> values) {
    deque<int> queue_values;
    while (!values.empty()) {
        queue_values.push_back(values.back());
        values.pop_back();
    }
    while (!queue_values.empty()) {
        values.push_back(queue_values.front());
        queue_values.pop_front();
    }
    return values;
}

/**
 * @brief Reverse a stack using one additional stack.
 * @param values vector<int> Stack stored as a vector where the back element is the top.
 * @return vector<int> Reversed stack.
 */
vector<int> reverse_stack_with_one_stack(vector<int> values) {
    vector<int> temp;
    while (!values.empty()) {
        int x = values.back();
        values.pop_back();
        while (!temp.empty() && temp.back() > x) {
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
 * @brief Run the stack-reversal demonstrations.
 * @return int Exit status code returned to the operating system.
 */
int main() {
    vector<int> values = {1, 2, 3, 4, 5};
    print_vector(reverse_stack_with_two_stacks(values));
    cout << '\n';
    print_vector(reverse_stack_with_one_queue(values));
    cout << '\n';
    print_vector(reverse_stack_with_one_stack(values));
    cout << '\n';
    return 0;
}
