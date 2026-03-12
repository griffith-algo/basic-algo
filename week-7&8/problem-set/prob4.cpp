/**
 * @file prob4.cpp
 * @brief C++ version of the BST split, merge, and concatenate example.
 */

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
};

/**
 * @brief Split a BST into values smaller than k and values at least k.
 * @param root TreeNode* Root of the BST to split.
 * @param k int Split value.
 * @return pair<TreeNode*, TreeNode*> Pair containing the left and right split trees.
 */
pair<TreeNode*, TreeNode*> split_tree(TreeNode* root, int k) {
    if (root == nullptr) {
        return {nullptr, nullptr};
    }
    if (root->val < k) {
        auto split = split_tree(root->right, k);
        root->right = split.first;
        return {root, split.second};
    }
    auto split = split_tree(root->left, k);
    root->left = split.second;
    return {split.first, root};
}

/**
 * @brief Insert a value into a BST.
 * @param root TreeNode* Root of the BST.
 * @param value int Value to insert.
 * @return TreeNode* Root of the updated BST.
 */
TreeNode* insert(TreeNode* root, int value) {
    if (root == nullptr) {
        return new TreeNode{value};
    }
    if (value < root->val) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

/**
 * @brief Return the inorder traversal of a BST.
 * @param node TreeNode* Current node visited by the recursive call.
 * @return vector<int> Inorder traversal values.
 */
vector<int> in_order_traversal(TreeNode* node) {
    if (node == nullptr) {
        return {};
    }
    vector<int> left = in_order_traversal(node->left);
    vector<int> right = in_order_traversal(node->right);
    left.push_back(node->val);
    left.insert(left.end(), right.begin(), right.end());
    return left;
}

/**
 * @brief Merge two sorted arrays into one sorted array.
 * @param arr1 const vector<int>& First sorted list.
 * @param arr2 const vector<int>& Second sorted list.
 * @return vector<int> Merged sorted list.
 */
vector<int> merge_sorted_arrays(const vector<int>& arr1, const vector<int>& arr2) {
    vector<int> merged;
    size_t i = 0;
    size_t j = 0;

    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] <= arr2[j]) {
            merged.push_back(arr1[i++]);
        } else {
            merged.push_back(arr2[j++]);
        }
    }
    merged.insert(merged.end(), arr1.begin() + static_cast<long>(i), arr1.end());
    merged.insert(merged.end(), arr2.begin() + static_cast<long>(j), arr2.end());
    return merged;
}

/**
 * @brief Build a balanced BST from a sorted array.
 * @param arr const vector<int>& Sorted list of integers.
 * @return TreeNode* Root of the balanced BST.
 */
TreeNode* build_balanced_bst(const vector<int>& arr) {
    if (arr.empty()) {
        return nullptr;
    }
    size_t mid = arr.size() / 2;
    TreeNode* root = new TreeNode{arr[mid]};
    root->left = build_balanced_bst(vector<int>(arr.begin(), arr.begin() + static_cast<long>(mid)));
    root->right = build_balanced_bst(vector<int>(arr.begin() + static_cast<long>(mid) + 1, arr.end()));
    return root;
}

/**
 * @brief Join two BSTs by merging their inorder traversals and rebuilding a balanced BST.
 * @param tree1 TreeNode* First BST.
 * @param tree2 TreeNode* Second BST.
 * @return TreeNode* Root of the combined balanced BST.
 */
TreeNode* concatenate_trees(TreeNode* tree1, TreeNode* tree2) {
    vector<int> merged_values = merge_sorted_arrays(in_order_traversal(tree1), in_order_traversal(tree2));
    return build_balanced_bst(merged_values);
}

/**
 * @brief Create one new tree node.
 * @param value int Value to store in the new node.
 * @return TreeNode* Pointer to the created node.
 */
TreeNode* create_node(int value) {
    return new TreeNode{value};
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
 * @brief Run the BST split, merge, and concatenation demonstrations.
 * @return int Exit status code returned to the operating system.
 */
int main() {
    vector<int> values = {50, 30, 70, 20, 40, 54, 80};
    TreeNode* root = nullptr;
    for (int value : values) {
        root = insert(root, value);
    }

    cout << "Original In-order: ";
    print_vector(in_order_traversal(root));
    cout << '\n';

    auto split = split_tree(root, 54);
    cout << "Left tree In-order: ";
    print_vector(in_order_traversal(split.first));
    cout << "\nRight tree In-order: ";
    print_vector(in_order_traversal(split.second));
    cout << '\n';

    TreeNode* tree1 = create_node(20);
    tree1->left = create_node(10);
    tree1->right = create_node(30);

    TreeNode* tree2 = create_node(50);
    tree2->left = create_node(40);
    tree2->right = create_node(60);

    vector<int> merged_array = merge_sorted_arrays(in_order_traversal(tree1), in_order_traversal(tree2));
    TreeNode* merged_tree = build_balanced_bst(merged_array);
    cout << "Merged Tree In-order: ";
    print_vector(in_order_traversal(merged_tree));
    cout << '\n';

    TreeNode* concatenated_tree = concatenate_trees(tree1, tree2);
    cout << "Concatenated Tree In-order: ";
    print_vector(in_order_traversal(concatenated_tree));
    cout << '\n';
    return 0;
}
