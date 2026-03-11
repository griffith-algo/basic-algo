#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

/**
 * @brief Search a sorted list using one equality test and one ordering test per loop.
 * @param values const vector<int>& The vector of values processed by the function.
 * @param target int The target peg, basket, or value used in the example.
 * @return int The integer result produced by the algorithm.
 */
int two_way_comparison_binary_search(const vector<int>& values, int target) {
    int left = 0;
    int right = static_cast<int>(values.size()) - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (values[mid] == target) return mid;
        if (values[mid] <= target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

/**
 * @brief Print the heap sideways so its tree shape is easier to see.
 * @param heap const vector<int>& The heap values used in the example.
 * @param index int The index value used by this function.
 * @param indent int The indent value used by this function.
 * @return void This function updates data or prints results and does not return a value.
 */
void print_heap(const vector<int>& heap, int index = 0, int indent = 0) {
    if (index >= static_cast<int>(heap.size())) return;
    print_heap(heap, 2 * index + 2, indent + 2);
    cout << string(indent, ' ') << heap[index] << '\n';
    print_heap(heap, 2 * index + 1, indent + 2);
}

/**
 * @brief Return true when the heap satisfies the min-heap property.
 * @param heap const vector<int>& The heap values used in the example.
 * @return bool True when the required condition is satisfied, otherwise false.
 */
bool is_min_heap(const vector<int>& heap) {
    for (size_t i = 0; i < heap.size() / 2; ++i) {
        size_t left = 2 * i + 1;
        size_t right = 2 * i + 2;
        if (left < heap.size() && heap[i] > heap[left]) return false;
        if (right < heap.size() && heap[i] > heap[right]) return false;
    }
    return true;
}

/**
 * @brief Return true when the heap satisfies the max-heap property.
 * @param heap const vector<int>& The heap values used in the example.
 * @return bool True when the required condition is satisfied, otherwise false.
 */
bool is_max_heap(const vector<int>& heap) {
    for (size_t i = 0; i < heap.size() / 2; ++i) {
        size_t left = 2 * i + 1;
        size_t right = 2 * i + 2;
        if (left < heap.size() && heap[i] < heap[left]) return false;
        if (right < heap.size() && heap[i] < heap[right]) return false;
    }
    return true;
}

struct TreeNode {
    int value;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
};

/**
 * @brief Count every node in the binary tree.
 * @param node TreeNode* The node currently processed by the function.
 * @return int The integer result produced by the algorithm.
 */
int count_nodes(TreeNode* node) {
    if (node == nullptr) return 0;
    return 1 + count_nodes(node->left) + count_nodes(node->right);
}

/**
 * @brief Count the leaves in the binary tree.
 * @param node TreeNode* The node currently processed by the function.
 * @return int The integer result produced by the algorithm.
 */
int count_leaves(TreeNode* node) {
    if (node == nullptr) return 0;
    if (node->left == nullptr && node->right == nullptr) return 1;
    return count_leaves(node->left) + count_leaves(node->right);
}

/**
 * @brief Count how many nodes have a right child.
 * @param node TreeNode* The node currently processed by the function.
 * @return int The integer result produced by the algorithm.
 */
int count_right_children(TreeNode* node) {
    if (node == nullptr) return 0;
    int current = node->right != nullptr ? 1 : 0;
    return current + count_right_children(node->left) + count_right_children(node->right);
}

/**
 * @brief Return the height of the tree.
 * @param node TreeNode* The node currently processed by the function.
 * @return int The integer result produced by the algorithm.
 */
int tree_height(TreeNode* node) {
    if (node == nullptr) return 0;
    return 1 + max(tree_height(node->left), tree_height(node->right));
}

/**
 * @brief Remove all leaf nodes from the tree.
 * @param node TreeNode* The node currently processed by the function.
 * @return TreeNode* The value produced by this function.
 */
TreeNode* delete_leaves(TreeNode* node) {
    if (node == nullptr) return nullptr;
    if (node->left == nullptr && node->right == nullptr) return nullptr;
    node->left = delete_leaves(node->left);
    node->right = delete_leaves(node->right);
    return node;
}

/**
 * @brief Check whether the tree satisfies the binary-search-tree property.
 * @param node TreeNode* The node currently processed by the function.
 * @param lower int The lower value used by this function.
 * @param upper int The upper value used by this function.
 * @return bool True when the required condition is satisfied, otherwise false.
 */
bool is_bst(TreeNode* node, int lower, int upper) {
    if (node == nullptr) return true;
    if (!(lower < node->value && node->value < upper)) return false;
    return is_bst(node->left, lower, node->value) && is_bst(node->right, node->value, upper);
}

/**
 * @brief Rebuild a binary tree from preorder and inorder traversals.
 * @param preorder const vector<int>& The preorder value used by this function.
 * @param inorder const vector<int>& The inorder value used by this function.
 * @return TreeNode* The value produced by this function.
 */
TreeNode* build_tree(const vector<int>& preorder, const vector<int>& inorder) {
    if (preorder.empty()) return nullptr;
    int root_value = preorder[0];
    auto split = find(inorder.begin(), inorder.end(), root_value) - inorder.begin();
    TreeNode* root = new TreeNode{root_value};
    root->left = build_tree(vector<int>(preorder.begin() + 1, preorder.begin() + 1 + split),
                            vector<int>(inorder.begin(), inorder.begin() + split));
    root->right = build_tree(vector<int>(preorder.begin() + 1 + split, preorder.end()),
                             vector<int>(inorder.begin() + split + 1, inorder.end()));
    return root;
}

/**
 * @brief Return the inorder traversal of the tree.
 * @param node TreeNode* The node currently processed by the function.
 * @return vector<int> The vector produced by the algorithm.
 */
vector<int> inorder_traversal(TreeNode* node) {
    if (node == nullptr) return {};
    vector<int> left = inorder_traversal(node->left);
    vector<int> right = inorder_traversal(node->right);
    left.push_back(node->value);
    left.insert(left.end(), right.begin(), right.end());
    return left;
}

/**
 * @brief Return the preorder traversal of the tree.
 * @param node TreeNode* The node currently processed by the function.
 * @return vector<int> The vector produced by the algorithm.
 */
vector<int> preorder_traversal(TreeNode* node) {
    if (node == nullptr) return {};
    vector<int> left = preorder_traversal(node->left);
    vector<int> right = preorder_traversal(node->right);
    vector<int> result = {node->value};
    result.insert(result.end(), left.begin(), left.end());
    result.insert(result.end(), right.begin(), right.end());
    return result;
}

/**
 * @brief Insert a new value into the binary search tree.
 * @param root TreeNode* The root node of the current tree.
 * @param value int The value value used by this function.
 * @return TreeNode* The value produced by this function.
 */
TreeNode* insert(TreeNode* root, int value) {
    if (root == nullptr) return new TreeNode{value};
    if (value < root->value) root->left = insert(root->left, value);
    else root->right = insert(root->right, value);
    return root;
}

/**
 * @brief Split the binary search tree into values smaller than k and values at least k.
 * @param root TreeNode* The root node of the current tree.
 * @param k int The split or comparison value used by the function.
 * @return pair<TreeNode*, TreeNode*> The pair of values produced by the algorithm.
 */
pair<TreeNode*, TreeNode*> split_tree(TreeNode* root, int k) {
    if (root == nullptr) return {nullptr, nullptr};
    if (root->value < k) {
        auto [left_tree, right_tree] = split_tree(root->right, k);
        root->right = left_tree;
        return {root, right_tree};
    }
    auto [left_tree, right_tree] = split_tree(root->left, k);
    root->left = right_tree;
    return {left_tree, root};
}

/**
 * @brief Merge two sorted arrays into one sorted array.
 * @param left const vector<int>& The left-side data or left boundary used by the algorithm.
 * @param right const vector<int>& The right-side data or right boundary used by the algorithm.
 * @return vector<int> The vector produced by the algorithm.
 */
vector<int> merge_sorted_arrays(const vector<int>& left, const vector<int>& right) {
    vector<int> merged;
    size_t i = 0;
    size_t j = 0;
    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) merged.push_back(left[i++]);
        else merged.push_back(right[j++]);
    }
    merged.insert(merged.end(), left.begin() + static_cast<long>(i), left.end());
    merged.insert(merged.end(), right.begin() + static_cast<long>(j), right.end());
    return merged;
}

/**
 * @brief Build a balanced binary search tree from a sorted list.
 * @param values const vector<int>& The vector of values processed by the function.
 * @return TreeNode* The value produced by this function.
 */
TreeNode* build_balanced_bst(const vector<int>& values) {
    if (values.empty()) return nullptr;
    size_t mid = values.size() / 2;
    TreeNode* root = new TreeNode{values[mid]};
    root->left = build_balanced_bst(vector<int>(values.begin(), values.begin() + static_cast<long>(mid)));
    root->right = build_balanced_bst(vector<int>(values.begin() + static_cast<long>(mid) + 1, values.end()));
    return root;
}

/**
 * @brief Combine the values from two trees into one balanced binary search tree.
 * @param tree1 TreeNode* The tree1 value used by this function.
 * @param tree2 TreeNode* The tree2 value used by this function.
 * @return TreeNode* The value produced by this function.
 */
TreeNode* concatenate_trees(TreeNode* tree1, TreeNode* tree2) {
    return build_balanced_bst(merge_sorted_arrays(inorder_traversal(tree1), inorder_traversal(tree2)));
}

/**
 * @brief Return true when all values in the list are distinct.
 * @param values const vector<int>& The vector of values processed by the function.
 * @return bool True when the required condition is satisfied, otherwise false.
 */
bool is_distinct(const vector<int>& values) {
    vector<vector<int>> table(10);
    for (int value : values) {
        int bucket = value % 10;
        if (find(table[bucket].begin(), table[bucket].end(), value) != table[bucket].end()) {
            return false;
        }
        table[bucket].push_back(value);
    }
    return true;
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
        if (i + 1 != values.size()) cout << ", ";
    }
    cout << ']';
}

/**
 * @brief Run the small demonstration for this teaching example.
 * @return int The integer result produced by the algorithm.
 */
int main() {
    cout << "Two-way comparison binary search: "
         << two_way_comparison_binary_search({3, 14, 27, 31, 39, 42, 55}, 31) << "\n\n";

    cout << "Min-heap visualisation:\n";
    print_heap({1, 2, 3, 4, 5, 6, 7});
    cout << boolalpha;
    cout << "Valid max-heap: " << is_max_heap({9, 7, 6, 4, 3, 5, 1}) << '\n';
    cout << "Valid min-heap: " << is_min_heap({1, 2, 3, 4, 5, 6, 7}) << "\n\n";

    TreeNode* root = new TreeNode{1};
    root->left = new TreeNode{2};
    root->right = new TreeNode{3};
    root->left->left = new TreeNode{4};
    root->left->right = new TreeNode{5};
    root->right->right = new TreeNode{6};
    cout << "Nodes: " << count_nodes(root) << ", leaves: " << count_leaves(root)
         << ", right children: " << count_right_children(root)
         << ", height: " << tree_height(root) << '\n';
    root = delete_leaves(root);
    cout << "After deleting leaves (in-order): ";
    print_vector(inorder_traversal(root));
    cout << "\n\n";

    TreeNode* bst = nullptr;
    for (int value : {50, 30, 70, 20, 40, 54, 80}) bst = insert(bst, value);
    auto [left_tree, right_tree] = split_tree(bst, 54);
    cout << "Split BST left part: ";
    print_vector(inorder_traversal(left_tree));
    cout << '\n';
    cout << "Split BST right part: ";
    print_vector(inorder_traversal(right_tree));
    cout << "\n\n";

    TreeNode* tree1 = nullptr;
    for (int value : {20, 10, 30}) tree1 = insert(tree1, value);
    TreeNode* tree2 = nullptr;
    for (int value : {50, 40, 60}) tree2 = insert(tree2, value);
    TreeNode* merged = concatenate_trees(tree1, tree2);
    cout << "Concatenated BST values: ";
    print_vector(inorder_traversal(merged));
    cout << '\n';

    TreeNode* rebuilt = build_tree({1, 2, 4, 5, 3, 6, 7}, {4, 2, 5, 1, 6, 3, 7});
    cout << "Rebuilt preorder: ";
    print_vector(preorder_traversal(rebuilt));
    cout << '\n';
    cout << "Is distinct [1, 11, 21, 31]: " << is_distinct({1, 11, 21, 31}) << '\n';
    cout << "Is BST [5-root example]: " << is_bst(merged, -1000000, 1000000) << '\n';
    return 0;
}
