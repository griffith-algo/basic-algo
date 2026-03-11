"""Prob3 example.

This file belongs to the week 12 geometry and compression examples. It builds a
Huffman code, uses it to encode a string, and then decodes the result again.
"""

import heapq


class Node:
    """Store one node used by the surrounding example."""

    def __init__(self, frequency, symbol=None, left=None, right=None):
        """Store the frequency and the children used in the Huffman tree.

        Args:
            frequency (object): The frequency input used by this function.
            symbol (object): The symbol input used by this function.
            left (object): The left boundary or left-side data used by the algorithm.
            right (object): The right boundary or right-side data used by the algorithm.

        Returns:
            None: This function updates data or prints results and does not return a value.
        """
        self.frequency = frequency
        self.symbol = symbol
        self.left = left
        self.right = right

    def __lt__(self, other):
        """Allow Python's heap to order nodes by their frequency.

        Args:
            other (object): The other input used by this function.

        Returns:
            bool: True when the required condition is satisfied, otherwise False.
        """
        return self.frequency < other.frequency


def build_huffman_tree(alphabet, frequencies):
    """Build a Huffman tree from the alphabet frequencies.

    Args:
        alphabet (list): The symbols used to build the Huffman tree.
        frequencies (dict): The dictionary that stores symbol frequencies.

    Returns:
        object: The value produced by this function.
    """
    priority_queue = [Node(frequencies[symbol], symbol) for symbol in alphabet]
    heapq.heapify(priority_queue)

    while len(priority_queue) > 1:
        left_node = heapq.heappop(priority_queue)
        right_node = heapq.heappop(priority_queue)
        parent = Node(left_node.frequency + right_node.frequency, left=left_node, right=right_node)
        heapq.heappush(priority_queue, parent)

    return priority_queue[0]


def dfs_traversal(node, codeword, codeword_dict):
    """Traverse the Huffman tree to assign a bit string to each symbol.

    Args:
        node (object): The node currently processed by the function.
        codeword (object): The codeword input used by this function.
        codeword_dict (dict): The codeword_dict input used by this function.

    Returns:
        None: This function updates data or prints results and does not return a value.
    """
    if node.symbol is not None:
        codeword_dict[node.symbol] = codeword or "0"
        return

    dfs_traversal(node.left, codeword + "0", codeword_dict)
    dfs_traversal(node.right, codeword + "1", codeword_dict)


def get_codewords(root_node):
    """Return the Huffman codeword for each symbol.

    Args:
        root_node (object): The root node of the current tree.

    Returns:
        dict: The dictionary produced by the algorithm.
    """
    codeword_dict = {}
    dfs_traversal(root_node, "", codeword_dict)
    return codeword_dict


def huffman_encode(input_string, codewords):
    """Encode a string using the supplied Huffman codewords.

    Args:
        input_string (str): The input_string input used by this function.
        codewords (dict): The dictionary that maps each symbol to its Huffman code.

    Returns:
        str: The string produced by the algorithm.
    """
    return "".join(codewords[symbol] for symbol in input_string)


def huffman_decode(encoded_string, root_node):
    """Decode a Huffman bit string back into text.

    Args:
        encoded_string (object): The encoded_string input used by this function.
        root_node (object): The root node of the current tree.

    Returns:
        str: The string produced by the algorithm.
    """
    decoded_string = []
    current_node = root_node

    for bit in encoded_string:
        current_node = current_node.left if bit == "0" else current_node.right

        if current_node.symbol is not None:
            decoded_string.append(current_node.symbol)
            current_node = root_node

    return "".join(decoded_string)


def main():
    """Run the small demonstration for this teaching example.

    Returns:
        None: This function updates data or prints results and does not return a value.
    """
    alphabet = ["A", "B", "C", "D", "E"]
    frequencies = {"A": 1, "B": 1, "C": 1, "D": 1, "E": 12}
    input_string = "ABCDEABCDEABCDEE"

    root_node = build_huffman_tree(alphabet, frequencies)
    codewords = get_codewords(root_node)
    encoded_string = huffman_encode(input_string, codewords)
    decoded_string = huffman_decode(encoded_string, root_node)

    print("Codewords:", codewords)
    print("Encoded string:", encoded_string)
    print("Decoded string:", decoded_string)


if __name__ == "__main__":
    main()
