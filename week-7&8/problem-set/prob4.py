"""Prob4 example.

This file belongs to the week 7 and 8 tree and hashing practice solutions. It
contains three binary-search-tree tasks: splitting, merging, and concatenating.
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
        self.val = value
        self.left = None
        self.right = None


def split_tree(root, k):
    """Split a binary search tree into values smaller than k and values at least k.

    Args:
        root (object): The root node of the current tree.
        k (int): The k input used by this function.

    Returns:
        tuple: The tuple of values produced by the algorithm.
    """
    if root is None:
        return None, None

    if root.val < k:
        left_tree, right_tree = split_tree(root.right, k)
        root.right = left_tree
        return root, right_tree

    left_tree, right_tree = split_tree(root.left, k)
    root.left = right_tree
    return left_tree, root


def insert(root, value):
    """Insert a new value into the binary search tree.

    Args:
        root (object): The root node of the current tree.
        value (int): The value input used by this function.

    Returns:
        object: The value produced by this function.
    """
    if root is None:
        return TreeNode(value)

    if value < root.val:
        root.left = insert(root.left, value)
    else:
        root.right = insert(root.right, value)
    return root


def in_order_traversal(node):
    """Return the inorder traversal of the tree.

    Args:
        node (object): The node currently processed by the function.

    Returns:
        list: The list produced by the algorithm.
    """
    if node is None:
        return []
    return in_order_traversal(node.left) + [node.val] + in_order_traversal(node.right)


def merge_sorted_arrays(arr1, arr2):
    """Merge two sorted lists into one sorted list.

    Args:
        arr1 (object): The arr1 input used by this function.
        arr2 (object): The arr2 input used by this function.

    Returns:
        list: The list produced by the algorithm.
    """
    merged = []
    i = 0
    j = 0

    while i < len(arr1) and j < len(arr2):
        if arr1[i] <= arr2[j]:
            merged.append(arr1[i])
            i += 1
        else:
            merged.append(arr2[j])
            j += 1

    merged.extend(arr1[i:])
    merged.extend(arr2[j:])
    return merged


def build_balanced_bst(arr):
    """Build a balanced binary search tree from a sorted list.

    Args:
        arr (list): The list being processed by the algorithm.

    Returns:
        object: The value produced by this function.
    """
    if not arr:
        return None

    mid = len(arr) // 2
    root = TreeNode(arr[mid])
    root.left = build_balanced_bst(arr[:mid])
    root.right = build_balanced_bst(arr[mid + 1 :])
    return root


def concatenate_trees(tree1, tree2):
    """Join two binary search trees by rebuilding a balanced tree from both.

    Args:
        tree1 (object): The tree1 input used by this function.
        tree2 (object): The tree2 input used by this function.

    Returns:
        object: The value produced by this function.
    """
    merged_values = merge_sorted_arrays(in_order_traversal(tree1), in_order_traversal(tree2))
    return build_balanced_bst(merged_values)


def create_node(value):
    """Create and return a new tree node.

    Args:
        value (int): The value input used by this function.

    Returns:
        object: The value produced by this function.
    """
    return TreeNode(value)


def main():
    """Run the small demonstration for this teaching example.

    Returns:
        None: This function updates data or prints results and does not return a value.
    """
    values = [50, 30, 70, 20, 40, 54, 80]
    root = None
    for value in values:
        root = insert(root, value)

    print("Original In-order:", in_order_traversal(root))
    left_tree, right_tree = split_tree(root, 54)
    print("Left tree In-order:", in_order_traversal(left_tree))
    print("Right tree In-order:", in_order_traversal(right_tree))

    tree1 = create_node(20)
    tree1.left = create_node(10)
    tree1.right = create_node(30)

    tree2 = create_node(50)
    tree2.left = create_node(40)
    tree2.right = create_node(60)

    merged_array = merge_sorted_arrays(in_order_traversal(tree1), in_order_traversal(tree2))
    merged_tree = build_balanced_bst(merged_array)
    print("Merged Tree In-order:", in_order_traversal(merged_tree))

    concatenated_tree = concatenate_trees(tree1, tree2)
    print("Concatenated Tree In-order:", in_order_traversal(concatenated_tree))


if __name__ == "__main__":
    main()
