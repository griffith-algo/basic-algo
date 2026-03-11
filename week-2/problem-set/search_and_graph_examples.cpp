#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * @brief Print integer-division hints for the share-calculation exercise.
 * @param n int The size value or number of recursive steps used by the function.
 * @return void This function updates data or prints results and does not return a value.
 */
void print_share_hints(int n) {
    cout << "Integer-division hints for n = " << n << ":\n";
    for (int i = 1; i <= n; ++i) {
        cout << n << " // " << i << " = " << (n / i) << '\n';
    }
}

struct Node {
    int value;
    int index;
    Node* next = nullptr;
    Node* down = nullptr;
};

/**
 * @brief Build a linked list from the given values.
 * @param values const vector<int>& The vector of values processed by the function.
 * @return Node* The value produced by this function.
 */
Node* build_linked_list(const vector<int>& values) {
    Node* head = nullptr;
    Node* tail = nullptr;
    for (int index = 0; index < static_cast<int>(values.size()); ++index) {
        Node* node = new Node{values[index], index};
        if (head == nullptr) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }
    return head;
}

/**
 * @brief Build a simple two-level skip list from the given values.
 * @param values const vector<int>& The vector of values processed by the function.
 * @param step int The step value used by this function.
 * @return Node* The value produced by this function.
 */
Node* build_skip_list(const vector<int>& values, int step = 2) {
    vector<Node*> bottom_nodes;
    for (int index = 0; index < static_cast<int>(values.size()); ++index) {
        bottom_nodes.push_back(new Node{values[index], index});
        if (index > 0) {
            bottom_nodes[index - 1]->next = bottom_nodes[index];
        }
    }

    vector<Node*> express_nodes;
    for (int index = 0; index < static_cast<int>(values.size()); index += step) {
        Node* node = new Node{values[index], index};
        node->down = bottom_nodes[index];
        express_nodes.push_back(node);
        if (express_nodes.size() > 1) {
            express_nodes[express_nodes.size() - 2]->next = node;
        }
    }
    return express_nodes.front();
}

/**
 * @brief Search a sorted list by repeatedly halving the search range.
 * @param values const vector<int>& The vector of values processed by the function.
 * @param target int The target peg, basket, or value used in the example.
 * @return int The integer result produced by the algorithm.
 */
int binary_search(const vector<int>& values, int target) {
    int left = 0;
    int right = static_cast<int>(values.size()) - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (values[mid] == target) {
            return mid;
        }
        if (values[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

/**
 * @brief Search a sorted list by estimating where the target should appear.
 * @param values const vector<int>& The vector of values processed by the function.
 * @param target int The target peg, basket, or value used in the example.
 * @return int The integer result produced by the algorithm.
 */
int interpolation_search(const vector<int>& values, int target) {
    int left = 0;
    int right = static_cast<int>(values.size()) - 1;
    while (left <= right && values[left] <= target && target <= values[right]) {
        if (values[left] == values[right]) {
            return values[left] == target ? left : -1;
        }
        int pos = left + (target - values[left]) * (right - left) / (values[right] - values[left]);
        if (values[pos] == target) {
            return pos;
        }
        if (values[pos] < target) {
            left = pos + 1;
        } else {
            right = pos - 1;
        }
    }
    return -1;
}

/**
 * @brief Scan a linked list from left to right until the target is found.
 * @param head Node* The first node in the linked structure.
 * @param target int The target peg, basket, or value used in the example.
 * @return int The integer result produced by the algorithm.
 */
int linear_search(Node* head, int target) {
    for (Node* current = head; current != nullptr && current->value <= target; current = current->next) {
        if (current->value == target) {
            return current->index;
        }
    }
    return -1;
}

/**
 * @brief Search through the skip list by moving across and then down.
 * @param head Node* The first node in the linked structure.
 * @param target int The target peg, basket, or value used in the example.
 * @return int The integer result produced by the algorithm.
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
 * @brief Build an adjacency matrix for an undirected graph.
 * @param num_vertices int The num_vertices value used by this function.
 * @param edges const vector<pair<int, int>>& The edges value used by this function.
 * @return vector<vector<int>> The vector produced by the algorithm.
 */
vector<vector<int>> create_adjacency_matrix(int num_vertices, const vector<pair<int, int>>& edges) {
    vector<vector<int>> matrix(num_vertices, vector<int>(num_vertices, 0));
    for (const auto& [u, v] : edges) {
        matrix[u][v] = 1;
        matrix[v][u] = 1;
    }
    return matrix;
}

/**
 * @brief Build an adjacency list for an undirected graph.
 * @param num_vertices int The num_vertices value used by this function.
 * @param edges const vector<pair<int, int>>& The edges value used by this function.
 * @return vector<vector<int>> The vector produced by the algorithm.
 */
vector<vector<int>> create_adjacency_list(int num_vertices, const vector<pair<int, int>>& edges) {
    vector<vector<int>> graph(num_vertices);
    for (const auto& [u, v] : edges) {
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    return graph;
}

/**
 * @brief Check whether the graph contains every possible edge.
 * @param matrix const vector<vector<int>>& The matrix or table processed by the function.
 * @return bool True when the required condition is satisfied, otherwise false.
 */
bool is_complete(const vector<vector<int>>& matrix) {
    for (int i = 0; i < static_cast<int>(matrix.size()); ++i) {
        for (int j = 0; j < static_cast<int>(matrix.size()); ++j) {
            if (i != j && matrix[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}

/**
 * @brief Check whether the graph contains a self-loop.
 * @param matrix const vector<vector<int>>& The matrix or table processed by the function.
 * @return bool True when the required condition is satisfied, otherwise false.
 */
bool has_loop(const vector<vector<int>>& matrix) {
    for (int i = 0; i < static_cast<int>(matrix.size()); ++i) {
        if (matrix[i][i] == 1) {
            return true;
        }
    }
    return false;
}

/**
 * @brief Check whether the graph contains an isolated vertex.
 * @param matrix const vector<vector<int>>& The matrix or table processed by the function.
 * @return bool True when the required condition is satisfied, otherwise false.
 */
bool has_isolated_vertex(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        if (all_of(row.begin(), row.end(), [](int value) { return value == 0; })) {
            return true;
        }
    }
    return false;
}

class PriorityQueueUnsortedArray {
public:
    /**
     * @brief Run the enqueue step used in this example.
     * @param item const string& The item value used by this function.
     * @param priority int The priority value used by the queue example.
     * @return void This function updates data or prints results and does not return a value.
     */
    void enqueue(const string& item, int priority) { items_.push_back({item, priority}); }
    /**
     * @brief Run the dequeue step used in this example.
     * @return string The string produced by the algorithm.
     */
    string dequeue() {
        auto it = max_element(items_.begin(), items_.end(), [](const auto& left, const auto& right) {
            return left.second < right.second;
        });
        string result = it->first;
        items_.erase(it);
        return result;
    }
private:
    vector<pair<string, int>> items_;
};

class PriorityQueueSortedArray {
public:
    /**
     * @brief Run the enqueue step used in this example.
     * @param item const string& The item value used by this function.
     * @param priority int The priority value used by the queue example.
     * @return void This function updates data or prints results and does not return a value.
     */
    void enqueue(const string& item, int priority) {
        items_.push_back({item, priority});
        sort(items_.begin(), items_.end(), [](const auto& left, const auto& right) {
            return left.second > right.second;
        });
    }
    /**
     * @brief Run the dequeue step used in this example.
     * @return string The string produced by the algorithm.
     */
    string dequeue() {
        string result = items_.front().first;
        items_.erase(items_.begin());
        return result;
    }
private:
    vector<pair<string, int>> items_;
};

struct TreePriorityNode {
    string item;
    int priority;
    TreePriorityNode* left = nullptr;
    TreePriorityNode* right = nullptr;
};

class PriorityQueueBinarySearchTree {
public:
    /**
     * @brief Run the enqueue step used in this example.
     * @param item const string& The item value used by this function.
     * @param priority int The priority value used by the queue example.
     * @return void This function updates data or prints results and does not return a value.
     */
    void enqueue(const string& item, int priority) { root_ = insert(root_, item, priority); }
    /**
     * @brief Run the dequeue step used in this example.
     * @return string The string produced by the algorithm.
     */
    string dequeue() {
        TreePriorityNode* parent = nullptr;
        TreePriorityNode* current = root_;
        while (current->left != nullptr) {
            parent = current;
            current = current->left;
        }
        string result = current->item;
        if (parent == nullptr) {
            root_ = current->right;
        } else {
            parent->left = current->right;
        }
        delete current;
        return result;
    }
private:
    /**
     * @brief Insert a new value into the binary search tree.
     * @param node TreePriorityNode* The node currently processed by the function.
     * @param item const string& The item value used by this function.
     * @param priority int The priority value used by the queue example.
     * @return TreePriorityNode* The value produced by this function.
     */
    TreePriorityNode* insert(TreePriorityNode* node, const string& item, int priority) {
        if (node == nullptr) {
            return new TreePriorityNode{item, priority};
        }
        if (priority > node->priority) {
            node->left = insert(node->left, item, priority);
        } else {
            node->right = insert(node->right, item, priority);
        }
        return node;
    }
    TreePriorityNode* root_ = nullptr;
};

struct Call {
    int priority;
    string caller;
    /**
     * @brief Run the operator> step used in this example.
     * @param other const Call& The other value used by this function.
     * @return bool True when the required condition is satisfied, otherwise false.
     */
    bool operator>(const Call& other) const { return priority > other.priority; }
};

class CallCenter {
public:
    /**
     * @brief Run the add call step used in this example.
     * @param priority int The priority value used by the queue example.
     * @param caller const string& The caller value used by this function.
     * @return void This function updates data or prints results and does not return a value.
     */
    void add_call(int priority, const string& caller) { calls_.push(Call{priority, caller}); }
    /**
     * @brief Run the answer call step used in this example.
     * @return string The string produced by the algorithm.
     */
    string answer_call() {
        if (calls_.empty()) {
            return "None";
        }
        string caller = calls_.top().caller;
        calls_.pop();
        return caller;
    }
private:
    priority_queue<Call, vector<Call>, greater<Call>> calls_;
};

class OrderQueue {
public:
    /**
     * @brief Run the add order step used in this example.
     * @param customer const string& The customer value used by this function.
     * @return void This function updates data or prints results and does not return a value.
     */
    void add_order(const string& customer) { orders_.push(customer); }
    /**
     * @brief Run the send order step used in this example.
     * @return string The string produced by the algorithm.
     */
    string send_order() {
        if (orders_.empty()) {
            return "None";
        }
        string customer = orders_.front();
        orders_.pop();
        return customer;
    }
private:
    queue<string> orders_;
};

/**
 * @brief Evaluate a postfix expression using a stack.
 * @param expression const string& The postfix expression evaluated by the function.
 * @return int The integer result produced by the algorithm.
 */
int evaluate_postfix(const string& expression) {
    stack<int> values;
    string token;
    for (size_t i = 0; i <= expression.size(); ++i) {
        if (i == expression.size() || expression[i] == ' ') {
            if (!token.empty()) {
                if (isdigit(static_cast<unsigned char>(token[0]))) {
                    values.push(stoi(token));
                } else {
                    int right = values.top();
                    values.pop();
                    int left = values.top();
                    values.pop();
                    if (token == "+") values.push(left + right);
                    if (token == "-") values.push(left - right);
                    if (token == "*") values.push(left * right);
                    if (token == "/") values.push(left / right);
                }
                token.clear();
            }
        } else {
            token.push_back(expression[i]);
        }
    }
    return values.top();
}

/**
 * @brief Return true when the two words contain the same letters.
 * @param left string The left-side data or left boundary used by the algorithm.
 * @param right string The right-side data or right boundary used by the algorithm.
 * @return bool True when the required condition is satisfied, otherwise false.
 */
bool is_anagram(string left, string right) {
    auto normalise = [](string& word) {
        string cleaned;
        for (char ch : word) {
            if (isalpha(static_cast<unsigned char>(ch))) {
                cleaned.push_back(static_cast<char>(tolower(static_cast<unsigned char>(ch))));
            }
        }
        sort(cleaned.begin(), cleaned.end());
        word = cleaned;
    };
    normalise(left);
    normalise(right);
    return left == right;
}

/**
 * @brief Run the small demonstration for this teaching example.
 * @return int The integer result produced by the algorithm.
 */
int main() {
    vector<int> values = {1, 3, 5, 7, 9, 11, 13, 15, 17};
    Node* linked_head = build_linked_list(values);
    Node* skip_head = build_skip_list(values);
    cout << "Binary search: " << binary_search(values, 11) << '\n';
    cout << "Interpolation search: " << interpolation_search(values, 11) << '\n';
    cout << "Linear search: " << linear_search(linked_head, 11) << '\n';
    cout << "Skip-list search: " << skip_list_search(skip_head, 11) << "\n\n";

    vector<pair<int, int>> edges = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}, {2, 3}};
    auto matrix = create_adjacency_matrix(4, edges);
    cout << boolalpha;
    cout << "Graph is complete: " << is_complete(matrix) << '\n';
    cout << "Graph has a loop: " << has_loop(matrix) << '\n';
    cout << "Graph has an isolated vertex: " << has_isolated_vertex(matrix) << "\n\n";

    PriorityQueueUnsortedArray pq1;
    pq1.enqueue("Task 1", 3);
    pq1.enqueue("Task 2", 1);
    pq1.enqueue("Task 3", 2);
    cout << "Priority queue (unsorted array): " << pq1.dequeue() << '\n';

    PriorityQueueSortedArray pq2;
    pq2.enqueue("Task 1", 3);
    pq2.enqueue("Task 2", 1);
    pq2.enqueue("Task 3", 2);
    cout << "Priority queue (sorted array): " << pq2.dequeue() << '\n';

    PriorityQueueBinarySearchTree pq3;
    pq3.enqueue("Task 1", 3);
    pq3.enqueue("Task 2", 1);
    pq3.enqueue("Task 3", 2);
    cout << "Priority queue (BST): " << pq3.dequeue() << "\n\n";

    CallCenter center;
    center.add_call(3, "John");
    center.add_call(1, "Jane");
    center.add_call(2, "Jim");
    cout << "First answered call: " << center.answer_call() << '\n';

    OrderQueue orders;
    orders.add_order("John");
    orders.add_order("Jane");
    cout << "First order sent: " << orders.send_order() << '\n';

    cout << "Postfix evaluation: " << evaluate_postfix("5 1 2 + 4 * + 3 -") << '\n';
    cout << "Anagram check (tea/eat): " << is_anagram("tea", "eat") << '\n';
    return 0;
}
