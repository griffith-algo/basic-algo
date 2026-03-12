/**
 * @file prob9.cpp
 * @brief C++ version of the queue-ordering examples.
 */

#include <deque>
#include <iostream>

using namespace std;

/**
 * @brief Sort a queue using two helper queues.
 * @param original_queue deque<int>& Queue to sort in ascending order.
 * @return void This function updates original_queue and does not return a value.
 */
void order_queue_two(deque<int>& original_queue) {
    deque<int> working_queue = original_queue;
    deque<int> buffer_queue;
    deque<int> sorted_queue;

    while (!working_queue.empty()) {
        int current_min = working_queue.front();
        working_queue.pop_front();

        while (!working_queue.empty()) {
            int value = working_queue.front();
            working_queue.pop_front();
            if (value < current_min) {
                buffer_queue.push_back(current_min);
                current_min = value;
            } else {
                buffer_queue.push_back(value);
            }
        }

        sorted_queue.push_back(current_min);
        working_queue = buffer_queue;
        buffer_queue.clear();
    }

    original_queue = sorted_queue;
}

/**
 * @brief Sort a queue using one helper queue.
 * @param original_queue deque<int>& Queue to sort in ascending order.
 * @return void This function updates original_queue and does not return a value.
 */
void order_queue_one(deque<int>& original_queue) {
    deque<int> working_queue = original_queue;
    deque<int> helper_queue;

    while (!working_queue.empty()) {
        int current_value = working_queue.front();
        working_queue.pop_front();

        while (!helper_queue.empty() && helper_queue.back() > current_value) {
            working_queue.push_back(helper_queue.back());
            helper_queue.pop_back();
        }

        helper_queue.push_back(current_value);
    }

    original_queue = helper_queue;
}

/**
 * @brief Print a queue in bracket form.
 * @param values const deque<int>& Queue to print. Each element has type int.
 * @return void This helper only prints data and does not return a value.
 */
void print_queue(const deque<int>& values) {
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
 * @brief Run the queue-ordering demonstrations.
 * @return int Exit status code returned to the operating system.
 */
int main() {
    deque<int> first_queue = {4, 1, 3, 2, 5};
    order_queue_two(first_queue);
    print_queue(first_queue);
    cout << '\n';

    deque<int> second_queue = {4, 1, 3, 2, 5};
    order_queue_one(second_queue);
    print_queue(second_queue);
    cout << '\n';
    return 0;
}
