/**
 * @file prob3.cpp
 * @brief C++ version of the binary-tree counting and rebuilding example.
 */

#include <iostream>
#include <limits>
#include <vector>

using namespace std;

struct TreeNode {
    int value;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
};

/**
 * @brief Count every node in a binary tree.
 * @param node TreeNode* Current node visited by the recursive call.
 * @return int Total number of nodes in the subtree rooted at node.
 */
int count_nodes(TreeNode* node) {
    if (node == nullptr) {
        return 0;
    }
    return 1 + count_nodes(node->left) + count_nodes(node->right);
}

/**
 * @brief Count the leaves in a binary tree.
 * @param node TreeNode* Current node visited by the recursive call.
 * @return int Number of leaf nodes in the subtree rooted at node.
 */
int count_leaves(TreeNode* node) {
    if (node == nullptr) {
        return 0;
    }
    if (node->left == nullptr && node->right == nullptr) {
        return 1;
    }
    return count_leaves(node->left) + count_leaves(node->right);
}

/**
 * @brief Count how many nodes have a right child.
 * @param node TreeNode* Current node visited by the recursive call.
 * @return int Number of nodes in the subtree that own a right child.
 */
int count_right_children(TreeNode* node) {
    if (node == nullptr) {
        return 0;
    }
    int current_count = node->right != nullptr ? 1 : 0;
    return current_count + count_right_children(node->left) + count_right_children(node->right);
}

/**
 * @brief Return the height of a binary tree.
 * @param node TreeNode* Current node visited by the recursive call.
 * @return int Height of the subtree rooted at node.
 */
int tree_height(TreeNode* node) {
    if (node == nullptr) {
        return 0;
    }
    return 1 + max(tree_height(node->left), tree_height(node->right));
}

/**
 * @brief Remove all leaves from a binary tree.
 * @param node TreeNode* Current node visited by the recursive call.
 * @return TreeNode* Root of the trimmed subtree.
 */
TreeNode* delete_leaves(TreeNode* node) {
    if (node == nullptr) {
        return nullptr;
    }
    if (node->left == nullptr && node->right == nullptr) {
        return nullptr;
    }

    node->left = delete_leaves(node->left);
    node->right = delete_leaves(node->right);
    return node;
}

/**
 * @brief Check whether a binary tree satisfies the binary-search-tree property.
 * @param node TreeNode* Current node visited by the recursive call.
 * @param lower int Smallest value allowed for the current subtree.
 * @param upper int Largest value allowed for the current subtree.
 * @return bool True when the subtree is a valid BST, otherwise false.
 */
bool is_bst(TreeNode* node, int lower = numeric_limits<int>::min(), int upper = numeric_limits<int>::max()) {
    if (node == nullptr) {
        return true;
    }
    if (!(lower < node->value && node->value < upper)) {
        return false;
    }
    return is_bst(node->left, lower, node->value) && is_bst(node->right, node->value, upper);
}

/**
 * @brief Return true when the tree is a binary search tree.
 * @param root TreeNode* Root of the tree being checked.
 * @return bool True when the whole tree satisfies the BST property, otherwise false.
 */
bool is_binary_search_tree(TreeNode* root) {
    return is_bst(root);
}

/**
 * @brief Rebuild a binary tree from preorder and inorder traversals.
 * @param pre_order const vector<int>& Preorder traversal of the tree.
 * @param in_order const vector<int>& Inorder traversal of the tree.
 * @return TreeNode* Root of the rebuilt tree.
 */
TreeNode* build_tree(const vector<int>& pre_order, const vector<int>& in_order) {
    if (pre_order.empty() || in_order.empty()) {
        return nullptr;
    }
    int root_value = pre_order[0];
    int root_index = 0;
    while (root_index < static_cast<int>(in_order.size()) && in_order[root_index] != root_value) {
        ++root_index;
    }

    TreeNode* root = new TreeNode{root_value};
    root->left = build_tree(
        vector<int>(pre_order.begin() + 1, pre_order.begin() + 1 + root_index),
        vector<int>(in_order.begin(), in_order.begin() + root_index)
    );
    root->right = build_tree(
        vector<int>(pre_order.begin() + 1 + root_index, pre_order.end()),
        vector<int>(in_order.begin() + root_index + 1, in_order.end())
    );
    return root;
}

/**
 * @brief Return the preorder traversal of a binary tree.
 * @param node TreeNode* Current node visited by the recursive call.
 * @return vector<int> Preorder traversal values.
 */
vector<int> pre_order_traversal(TreeNode* node) {
    if (node == nullptr) {
        return {};
    }
    vector<int> result = {node->value};
    vector<int> left = pre_order_traversal(node->left);
    vector<int> right = pre_order_traversal(node->right);
    result.insert(result.end(), left.begin(), left.end());
    result.insert(result.end(), right.begin(), right.end());
    return result;
}

/**
 * @brief Return the inorder traversal of a binary tree.
 * @param node TreeNode* Current node visited by the recursive call.
 * @return vector<int> Inorder traversal values.
 */
vector<int> in_order_traversal(TreeNode* node) {
    if (node == nullptr) {
        return {};
    }
    vector<int> left = in_order_traversal(node->left);
    vector<int> right = in_order_traversal(node->right);
    left.push_back(node->value);
    left.insert(left.end(), right.begin(), right.end());
    return left;
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
 * @brief Run the binary-tree demonstrations.
 * @return int Exit status code returned to the operating system.
 */
int main() {
    TreeNode* root = new TreeNode{1};
    root->left = new TreeNode{2};
    root->right = new TreeNode{3};
    root->left->left = new TreeNode{4};
    root->left->right = new TreeNode{5};
    root->right->right = new TreeNode{6};

    cout << "Number of nodes: " << count_nodes(root) << '\n';
    cout << "Number of leaves: " << count_leaves(root) << '\n';
    cout << "Number of right children: " << count_right_children(root) << '\n';
    cout << "Tree height: " << tree_height(root) << '\n';

    TreeNode* trimmed_root = delete_leaves(root);
    cout << "Tree after deleting leaves: ";
    print_vector(in_order_traversal(trimmed_root));
    cout << '\n';

    TreeNode* bst_root = new TreeNode{5};
    bst_root->left = new TreeNode{3};
    bst_root->right = new TreeNode{7};
    bst_root->left->left = new TreeNode{2};
    bst_root->left->right = new TreeNode{4};
    bst_root->right->left = new TreeNode{6};
    bst_root->right->right = new TreeNode{8};
    cout << "Is BST: " << boolalpha << is_binary_search_tree(bst_root) << '\n';

    vector<int> pre_order = {1, 2, 4, 5, 3, 6, 7};
    vector<int> in_order = {4, 2, 5, 1, 6, 3, 7};
    TreeNode* rebuilt_root = build_tree(pre_order, in_order);
    cout << "Reconstructed Pre-order: ";
    print_vector(pre_order_traversal(rebuilt_root));
    cout << "\nReconstructed In-order: ";
    print_vector(in_order_traversal(rebuilt_root));
    cout << '\n';
    return 0;
}
