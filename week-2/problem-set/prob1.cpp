/**
 * @file prob1.cpp
 * @brief C++ version of the array, linked-list, and skip-list search comparison.
 */

#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int value;
    int index;
    Node* next = nullptr;
    Node* down = nullptr;
};

class LinkedList {
public:
    /**
     * @brief Build the linked list from the given values.
     * @param values const vector<int>& Sorted integers to store in the list.
     */
    explicit LinkedList(const vector<int>& values) : head(nullptr), tail(nullptr), size(0) {
        for (int value : values) {
            append(value);
        }
    }

    /**
     * @brief Append one new node to the end of the linked list.
     * @param value int Value to store in the new node.
     * @return void This method updates the linked list and does not return a value.
     */
    void append(int value) {
        Node* new_node = new Node{value, size};
        if (head == nullptr) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
        ++size;
    }

    Node* head;

private:
    Node* tail;
    int size;
};

/**
 * @brief Search a sorted array by repeatedly halving the search range.
 * @param arr const vector<int>& Sorted list of integers.
 * @param target int Value to find in the list.
 * @return int Index of target when it is found, otherwise -1.
 */
int binary_search(const vector<int>& arr, int target) {
    int left = 0;
    int right = static_cast<int>(arr.size()) - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

/**
 * @brief Search a sorted array by estimating where the target should appear.
 * @param arr const vector<int>& Sorted list of integers.
 * @param target int Value to find in the list.
 * @return int Index of target when it is found, otherwise -1.
 */
int interpolation_search(const vector<int>& arr, int target) {
    int left = 0;
    int right = static_cast<int>(arr.size()) - 1;

    while (left <= right && arr[left] <= target && target <= arr[right]) {
        if (arr[left] == arr[right]) {
            return arr[left] == target ? left : -1;
        }

        int pos = left + ((target - arr[left]) * (right - left)) / (arr[right] - arr[left]);
        if (arr[pos] == target) {
            return pos;
        }
        if (arr[pos] < target) {
            left = pos + 1;
        } else {
            right = pos - 1;
        }
    }

    return -1;
}

/**
 * @brief Scan a linked list from left to right until the target is found.
 * @param head Node* First node of the linked list.
 * @param target int Value to find in the linked list.
 * @return int Original array index of target, or -1 when the value is absent.
 */
int linear_search(Node* head, int target) {
    Node* current = head;
    while (current != nullptr && current->value <= target) {
        if (current->value == target) {
            return current->index;
        }
        current = current->next;
    }
    return -1;
}

/**
 * @brief Build a two-level skip list from sorted values.
 * @param values const vector<int>& Sorted integers to store in the skip list.
 * @param step int Distance between express-lane nodes.
 * @return pair<Node*, Node*> Head of the express level and head of the bottom level.
 */
pair<Node*, Node*> build_skip_list(const vector<int>& values, int step = 2) {
    vector<Node*> bottom_nodes;
    for (int index = 0; index < static_cast<int>(values.size()); ++index) {
        bottom_nodes.push_back(new Node{values[index], index});
        if (index > 0) {
            bottom_nodes[index - 1]->next = bottom_nodes[index];
        }
    }

    vector<Node*> express_nodes;
    for (int index = 0; index < static_cast<int>(values.size()); index += step) {
        Node* express_node = new Node{values[index], index};
        express_node->down = bottom_nodes[index];
        express_nodes.push_back(express_node);
        if (express_nodes.size() > 1) {
            express_nodes[express_nodes.size() - 2]->next = express_nodes.back();
        }
    }

    return {express_nodes.front(), bottom_nodes.front()};
}

/**
 * @brief Search a two-level skip list by moving across and then down.
 * @param head Node* First express node of the skip list.
 * @param target int Value to find in the structure.
 * @return int Original array index of target, or -1 when the value is absent.
 */
int skip_list_search(Node* head, int target) {
    Node* current = head;

    while (current != nullptr) {
        while (current->next != nullptr && current->next->value <= target) {
            current = current->next;
        }
        if (current->value == target) {
            return current->index;
        }
        current = current->down;
    }

    return -1;
}

/**
 * @brief Run the search-structure demonstration.
 * @return int Exit status code returned to the operating system.
 */
int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11, 13, 15, 17};
    LinkedList linked_list(arr);
    pair<Node*, Node*> skip_list = build_skip_list(arr);

    cout << "Binary search: " << binary_search(arr, 11) << '\n';
    cout << "Interpolation search: " << interpolation_search(arr, 11) << '\n';
    cout << "Linear search on linked list: " << linear_search(linked_list.head, 11) << '\n';
    cout << "Skip-list search: " << skip_list_search(skip_list.first, 11) << '\n';
    return 0;
}
