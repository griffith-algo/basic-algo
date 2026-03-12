/**
 * @file prob8.cpp
 * @brief C++ version of the queue-using-two-stacks example.
 */

#include <iostream>
#include <stack>

using namespace std;

class Queue {
public:
    /**
     * @brief Insert a new item at the back of the queue.
     * @param item int Value to add to the queue.
     * @return void This method updates the queue and does not return a value.
     */
    void enqueue(int item) {
        enqueue_stack.push(item);
    }

    /**
     * @brief Remove and return the item at the front of the queue.
     * @return int Front value removed from the queue.
     */
    int dequeue() {
        if (dequeue_stack.empty()) {
            while (!enqueue_stack.empty()) {
                dequeue_stack.push(enqueue_stack.top());
                enqueue_stack.pop();
            }
        }
        if (dequeue_stack.empty()) {
            throw out_of_range("Queue is empty");
        }
        int value = dequeue_stack.top();
        dequeue_stack.pop();
        return value;
    }

    /**
     * @brief Return true when the queue stores no items.
     * @return bool True when both internal stacks are empty, otherwise false.
     */
    bool is_empty() const {
        return enqueue_stack.empty() && dequeue_stack.empty();
    }

private:
    stack<int> enqueue_stack;
    stack<int> dequeue_stack;
};

/**
 * @brief Run the queue demonstration.
 * @return int Exit status code returned to the operating system.
 */
int main() {
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout << q.dequeue() << '\n';
    q.enqueue(4);
    cout << q.dequeue() << '\n';
    cout << q.dequeue() << '\n';
    cout << q.dequeue() << '\n';
    cout << boolalpha << q.is_empty() << '\n';
    return 0;
}
