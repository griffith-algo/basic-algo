"""Prob3 example.

This file belongs to the week 7 and 8 tree and hashing practice solutions. It
collects several common binary-tree tasks in one place.
"""


class TreeNode:
    """Store one node in a binary tree."""

    def __init__(self, value):
        """Store the value and pointers to the left and right children.

        Args:
            value (int): The value input used by this function.

        Returns:
            None: This function updates data or prints results and does not return a value.
        """
        self.value = value
        self.left = None
        self.right = None


def count_nodes(node):
    """Count every node in the binary tree.

    Args:
        node (object): The node currently processed by the function.

    Returns:
        int: The integer result produced by the algorithm.
    """
    if node is None:
        return 0
    return 1 + count_nodes(node.left) + count_nodes(node.right)


def count_leaves(node):
    """Count the leaves in the binary tree.

    Args:
        node (object): The node currently processed by the function.

    Returns:
        int: The integer result produced by the algorithm.
    """
    if node is None:
        return 0
    if node.left is None and node.right is None:
        return 1
    return count_leaves(node.left) + count_leaves(node.right)


def count_right_children(node):
    """Count how many nodes have a right child.

    Args:
        node (object): The node currently processed by the function.

    Returns:
        int: The integer result produced by the algorithm.
    """
    if node is None:
        return 0

    current_count = 1 if node.right is not None else 0
    return current_count + count_right_children(node.left) + count_right_children(node.right)


def tree_height(node):
    """Return the height of the tree.

    Args:
        node (object): The node currently processed by the function.

    Returns:
        int: The integer result produced by the algorithm.
    """
    if node is None:
        return 0
    return 1 + max(tree_height(node.left), tree_height(node.right))


def delete_leaves(node):
    """Remove all leaf nodes from the tree.

    Args:
        node (object): The node currently processed by the function.

    Returns:
        object: The value produced by this function.
    """
    if node is None:
        return None
    if node.left is None and node.right is None:
        return None

    node.left = delete_leaves(node.left)
    node.right = delete_leaves(node.right)
    return node


def is_bst(node, lower=float("-inf"), upper=float("inf")):
    """Check whether the tree satisfies the binary-search-tree property.

    Args:
        node (object): The node currently processed by the function.
        lower (object): The lower input used by this function.
        upper (object): The upper input used by this function.

    Returns:
        bool: True when the required condition is satisfied, otherwise False.
    """
    if node is None:
        return True
    if not lower < node.value < upper:
        return False

    return is_bst(node.left, lower, node.value) and is_bst(node.right, node.value, upper)


def is_binary_search_tree(root):
    """Return True when the tree is a valid binary search tree.

    Args:
        root (object): The root node of the current tree.

    Returns:
        bool: True when the required condition is satisfied, otherwise False.
    """
    return is_bst(root)


def build_tree(pre_order, in_order):
    """Rebuild a binary tree from its preorder and inorder traversals.

    Args:
        pre_order (list): The preorder traversal used to rebuild the tree.
        in_order (list): The inorder traversal used to rebuild the tree.

    Returns:
        object: The value produced by this function.
    """
    if not pre_order or not in_order:
        return None

    root_value = pre_order[0]
    root_index = in_order.index(root_value)
    root = TreeNode(root_value)

    root.left = build_tree(pre_order[1 : root_index + 1], in_order[:root_index])
    root.right = build_tree(pre_order[root_index + 1 :], in_order[root_index + 1 :])
    return root


def pre_order_traversal(node):
    """Return the preorder traversal of the tree.

    Args:
        node (object): The node currently processed by the function.

    Returns:
        list: The list produced by the algorithm.
    """
    if node is None:
        return []
    return [node.value] + pre_order_traversal(node.left) + pre_order_traversal(node.right)


def in_order_traversal(node):
    """Return the inorder traversal of the tree.

    Args:
        node (object): The node currently processed by the function.

    Returns:
        list: The list produced by the algorithm.
    """
    if node is None:
        return []
    return in_order_traversal(node.left) + [node.value] + in_order_traversal(node.right)


def main():
    """Run the small demonstration for this teaching example.

    Returns:
        None: This function updates data or prints results and does not return a value.
    """
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.left.left = TreeNode(4)
    root.left.right = TreeNode(5)
    root.right.right = TreeNode(6)

    print(f"Number of nodes: {count_nodes(root)}")
    print(f"Number of leaves: {count_leaves(root)}")
    print(f"Number of right children: {count_right_children(root)}")
    print(f"Tree height: {tree_height(root)}")

    trimmed_root = delete_leaves(root)
    print("Tree after deleting leaves:", in_order_traversal(trimmed_root))

    bst_root = TreeNode(5)
    bst_root.left = TreeNode(3)
    bst_root.right = TreeNode(7)
    bst_root.left.left = TreeNode(2)
    bst_root.left.right = TreeNode(4)
    bst_root.right.left = TreeNode(6)
    bst_root.right.right = TreeNode(8)
    print("Is BST:", is_binary_search_tree(bst_root))

    pre_order = [1, 2, 4, 5, 3, 6, 7]
    in_order = [4, 2, 5, 1, 6, 3, 7]
    rebuilt_root = build_tree(pre_order, in_order)
    print("Reconstructed Pre-order:", pre_order_traversal(rebuilt_root))
    print("Reconstructed In-order:", in_order_traversal(rebuilt_root))


if __name__ == "__main__":
    main()
