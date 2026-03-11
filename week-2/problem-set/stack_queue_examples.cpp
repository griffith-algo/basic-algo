#include <algorithm>
#include <deque>
#include <iostream>
#include <queue>
#include <stack>
#include <tuple>
#include <vector>

using namespace std;

/**
 * @brief Solve the Tower of Hanoi problem iteratively using a stack.
 * @param n int The size value or number of recursive steps used by the function.
 * @param source char The source peg, basket, or container used in the example.
 * @param destination char The destination value used by this function.
 * @param auxiliary char The helper peg or container used in the example.
 * @return void This function updates data or prints results and does not return a value.
 */
void tower_of_hanoi(int n, char source, char destination, char auxiliary) {
    stack<tuple<int, char, char, char>> work;
    work.push({n, source, destination, auxiliary});

    while (!work.empty()) {
        auto [disks, src, dest, aux] = work.top();
        work.pop();
        if (disks == 1) {
            cout << "Move disk from " << src << " to " << dest << '\n';
        } else {
            work.push({disks - 1, aux, dest, src});
            work.push({1, src, dest, aux});
            work.push({disks - 1, src, aux, dest});
        }
    }
}

/**
 * @brief Compute the stock span for each day.
 * @param prices const vector<int>& The prices value used by this function.
 * @return vector<int> The vector produced by the algorithm.
 */
vector<int> stock_span(const vector<int>& prices) {
    vector<int> stack_indices;
    vector<int> spans;
    for (int i = 0; i < static_cast<int>(prices.size()); ++i) {
        int current_span = 1;
        while (!stack_indices.empty() && prices[stack_indices.back()] <= prices[i]) {
            current_span += spans[stack_indices.back()];
            stack_indices.pop_back();
        }
        spans.push_back(current_span);
        stack_indices.push_back(i);
    }
    return spans;
}

/**
 * @brief Reverse a stack using two temporary stacks.
 * @param values vector<int> The vector of values processed by the function.
 * @return vector<int> The vector produced by the algorithm.
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
 * @param values vector<int> The vector of values processed by the function.
 * @return vector<int> The vector produced by the algorithm.
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
 * @param values vector<int> The vector of values processed by the function.
 * @return vector<int> The vector produced by the algorithm.
 */
vector<int> reverse_stack_with_one_stack(vector<int> values) {
    vector<int> temp;
    while (!values.empty()) {
        int current = values.back();
        values.pop_back();
        while (!temp.empty() && temp.back() > current) {
            values.push_back(temp.back());
            temp.pop_back();
        }
        temp.push_back(current);
    }
    while (!temp.empty()) {
        values.push_back(temp.back());
        temp.pop_back();
    }
    return values;
}

/**
 * @brief Sort a stack using another stack as temporary storage.
 * @param values vector<int> The vector of values processed by the function.
 * @return vector<int> The vector produced by the algorithm.
 */
vector<int> sort_stack(vector<int> values) {
    vector<int> temp;
    while (!values.empty()) {
        int current = values.back();
        values.pop_back();
        while (!temp.empty() && temp.back() < current) {
            values.push_back(temp.back());
            temp.pop_back();
        }
        temp.push_back(current);
    }
    while (!temp.empty()) {
        values.push_back(temp.back());
        temp.pop_back();
    }
    return values;
}

class QueueWithTwoStacks {
public:
    /**
     * @brief Run the enqueue step used in this example.
     * @param value int The value value used by this function.
     * @return void This function updates data or prints results and does not return a value.
     */
    void enqueue(int value) { in_stack_.push(value); }
    /**
     * @brief Run the dequeue step used in this example.
     * @return int The integer result produced by the algorithm.
     */
    int dequeue() {
        if (out_stack_.empty()) {
            while (!in_stack_.empty()) {
                out_stack_.push(in_stack_.top());
                in_stack_.pop();
            }
        }
        int value = out_stack_.top();
        out_stack_.pop();
        return value;
    }
    /**
     * @brief Run the is empty step used in this example.
     * @return bool True when the required condition is satisfied, otherwise false.
     */
    bool is_empty() const { return in_stack_.empty() && out_stack_.empty(); }
private:
    stack<int> in_stack_;
    stack<int> out_stack_;
};

/**
 * @brief Sort a queue using two helper queues.
 * @param original_queue deque<int>& The original_queue value used by this function.
 * @return void This function updates data or prints results and does not return a value.
 */
void order_queue_two(deque<int>& original_queue) {
    deque<int> working = original_queue;
    deque<int> buffer;
    deque<int> sorted_queue;

    while (!working.empty()) {
        int current_min = working.front();
        working.pop_front();
        while (!working.empty()) {
            int value = working.front();
            working.pop_front();
            if (value < current_min) {
                buffer.push_back(current_min);
                current_min = value;
            } else {
                buffer.push_back(value);
            }
        }
        sorted_queue.push_back(current_min);
        working = buffer;
        buffer.clear();
    }
    original_queue = sorted_queue;
}

/**
 * @brief Sort a queue using one helper queue.
 * @param original_queue deque<int>& The original_queue value used by this function.
 * @return void This function updates data or prints results and does not return a value.
 */
void order_queue_one(deque<int>& original_queue) {
    deque<int> working = original_queue;
    deque<int> helper;
    while (!working.empty()) {
        int current = working.front();
        working.pop_front();
        while (!helper.empty() && helper.back() > current) {
            working.push_back(helper.back());
            helper.pop_back();
        }
        helper.push_back(current);
    }
    original_queue = helper;
}

template <typename T>
/**
 * @brief Print the vector in a beginner-friendly format.
 * @param values const vector<T>& The vector of values processed by the function.
 * @return void This function updates data or prints results and does not return a value.
 */
void print_vector(const vector<T>& values) {
    cout << '[';
    for (size_t i = 0; i < values.size(); ++i) {
        cout << values[i];
        if (i + 1 != values.size()) {
            cout << ", ";
        }
    }
    cout << ']';
}

/**
 * @brief Run the small demonstration for this teaching example.
 * @return int The integer result produced by the algorithm.
 */
int main() {
    cout << "Iterative Tower of Hanoi with 3 disks:\n";
    tower_of_hanoi(3, 'A', 'C', 'B');
    cout << '\n';

    cout << "Stock span: ";
    print_vector(stock_span({100, 80, 60, 70, 60, 75, 85}));
    cout << "\n\n";

    cout << "Reverse stack with two stacks: ";
    print_vector(reverse_stack_with_two_stacks({1, 2, 3, 4, 5}));
    cout << '\n';
    cout << "Reverse stack with one queue: ";
    print_vector(reverse_stack_with_one_queue({1, 2, 3, 4, 5}));
    cout << '\n';
    cout << "Reverse stack with one stack: ";
    print_vector(reverse_stack_with_one_stack({1, 2, 3, 4, 5}));
    cout << '\n';
    cout << "Sort stack: ";
    print_vector(sort_stack({1, 3, 2, 5, 4}));
    cout << "\n\n";

    QueueWithTwoStacks queue_example;
    queue_example.enqueue(1);
    queue_example.enqueue(2);
    queue_example.enqueue(3);
    cout << "Queue with two stacks dequeue order: "
         << queue_example.dequeue() << ' ' << queue_example.dequeue() << ' ' << queue_example.dequeue() << "\n";

    deque<int> queue_values = {4, 1, 3, 2, 5};
    order_queue_two(queue_values);
    cout << "Ordered queue with two helpers: ";
    for (int value : queue_values) cout << value << ' ';
    cout << '\n';

    deque<int> second_queue = {4, 1, 3, 2, 5};
    order_queue_one(second_queue);
    cout << "Ordered queue with one helper: ";
    for (int value : second_queue) cout << value << ' ';
    cout << '\n';
    return 0;
}
