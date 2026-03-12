/**
 * @file prob3.cpp
 * @brief C++ version of the three priority-queue implementations.
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

class PriorityQueueUnsortedArray {
public:
    /**
     * @brief Return true when the queue stores no items.
     * @return bool True when the queue is empty, otherwise false.
     */
    bool is_empty() const {
        return items.empty();
    }

    /**
     * @brief Insert a new item with an integer priority.
     * @param item const string& Task name or label to store.
     * @param priority int Priority value, where larger numbers mean higher priority.
     * @return void This method updates the queue and does not return a value.
     */
    void enqueue(const string& item, int priority) {
        items.push_back({item, priority});
    }

    /**
     * @brief Remove and return the highest-priority item.
     * @return string Stored label of the removed item, or an empty string when the queue is empty.
     */
    string dequeue() {
        if (is_empty()) {
            return "";
        }
        auto best = items.begin();
        for (auto it = items.begin(); it != items.end(); ++it) {
            if (it->second > best->second) {
                best = it;
            }
        }
        string result = best->first;
        items.erase(best);
        return result;
    }

private:
    vector<pair<string, int>> items;
};

class PriorityQueueSortedArray {
public:
    /**
     * @brief Return true when the queue stores no items.
     * @return bool True when the queue is empty, otherwise false.
     */
    bool is_empty() const {
        return items.empty();
    }

    /**
     * @brief Insert a new item and keep the array sorted by priority.
     * @param item const string& Task name or label to store.
     * @param priority int Priority value, where larger numbers mean higher priority.
     * @return void This method updates the queue and does not return a value.
     */
    void enqueue(const string& item, int priority) {
        items.push_back({item, priority});
        sort(items.begin(), items.end(), [](const auto& left, const auto& right) {
            return left.second > right.second;
        });
    }

    /**
     * @brief Remove and return the highest-priority item.
     * @return string Stored label of the removed item, or an empty string when the queue is empty.
     */
    string dequeue() {
        if (is_empty()) {
            return "";
        }
        string result = items.front().first;
        items.erase(items.begin());
        return result;
    }

private:
    vector<pair<string, int>> items;
};

struct Node {
    string item;
    int priority;
    Node* left = nullptr;
    Node* right = nullptr;
};

class PriorityQueueBinarySearchTree {
public:
    /**
     * @brief Return true when the tree-based queue stores no items.
     * @return bool True when the queue is empty, otherwise false.
     */
    bool is_empty() const {
        return root == nullptr;
    }

    /**
     * @brief Insert a new item into the binary-search-tree priority queue.
     * @param item const string& Task name or label to store.
     * @param priority int Priority value, where larger numbers mean higher priority.
     * @return void This method updates the queue and does not return a value.
     */
    void enqueue(const string& item, int priority) {
        root = insert(root, item, priority);
    }

    /**
     * @brief Remove and return the highest-priority item.
     * @return string Stored label of the removed item, or an empty string when the queue is empty.
     */
    string dequeue() {
        if (is_empty()) {
            return "";
        }

        Node* parent = nullptr;
        Node* current = root;
        while (current->left != nullptr) {
            parent = current;
            current = current->left;
        }

        string result = current->item;
        if (parent == nullptr) {
            root = current->right;
        } else {
            parent->left = current->right;
        }
        delete current;
        return result;
    }

private:
    /**
     * @brief Insert one node into the tree by its priority.
     * @param node Node* Current tree node visited by the recursive call.
     * @param item const string& Task name or label to store.
     * @param priority int Priority value, where larger numbers move to the left.
     * @return Node* Root of the updated subtree.
     */
    Node* insert(Node* node, const string& item, int priority) {
        if (node == nullptr) {
            return new Node{item, priority};
        }
        if (priority > node->priority) {
            node->left = insert(node->left, item, priority);
        } else {
            node->right = insert(node->right, item, priority);
        }
        return node;
    }

    Node* root = nullptr;
};

/**
 * @brief Run the priority-queue demonstrations.
 * @return int Exit status code returned to the operating system.
 */
int main() {
    PriorityQueueUnsortedArray pq1;
    pq1.enqueue("Task 1", 3);
    pq1.enqueue("Task 2", 1);
    pq1.enqueue("Task 3", 2);
    cout << pq1.dequeue() << '\n';
    cout << pq1.dequeue() << '\n';
    cout << pq1.dequeue() << '\n';

    PriorityQueueSortedArray pq2;
    pq2.enqueue("Task 1", 3);
    pq2.enqueue("Task 2", 1);
    pq2.enqueue("Task 3", 2);
    cout << pq2.dequeue() << '\n';
    cout << pq2.dequeue() << '\n';
    cout << pq2.dequeue() << '\n';

    PriorityQueueBinarySearchTree pq3;
    pq3.enqueue("Task 1", 3);
    pq3.enqueue("Task 2", 1);
    pq3.enqueue("Task 3", 2);
    cout << pq3.dequeue() << '\n';
    cout << pq3.dequeue() << '\n';
    cout << pq3.dequeue() << '\n';
    return 0;
}
