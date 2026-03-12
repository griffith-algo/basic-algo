/**
 * @file prob3.cpp
 * @brief C++ version of the Huffman-coding example.
 */

#include <iostream>
#include <memory>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct Node {
    int frequency;
    char symbol;
    shared_ptr<Node> left;
    shared_ptr<Node> right;

    /**
     * @brief Return true when the node has no children.
     * @return bool True when the node is a leaf, otherwise false.
     */
    bool is_leaf() const {
        return left == nullptr && right == nullptr;
    }
};

/**
 * @brief Build a Huffman tree from the alphabet frequencies.
 * @param alphabet const vector<char>& Symbols that appear in the alphabet.
 * @param frequencies const unordered_map<char, int>& Mapping from symbol to frequency count.
 * @return shared_ptr<Node> Root of the Huffman tree.
 */
shared_ptr<Node> build_huffman_tree(const vector<char>& alphabet,
                                    const unordered_map<char, int>& frequencies) {
    auto compare = [](const shared_ptr<Node>& left, const shared_ptr<Node>& right) {
        return left->frequency > right->frequency;
    };
    priority_queue<shared_ptr<Node>, vector<shared_ptr<Node>>, decltype(compare)> priority_queue(compare);

    for (char symbol : alphabet) {
        priority_queue.push(make_shared<Node>(Node{frequencies.at(symbol), symbol, nullptr, nullptr}));
    }

    while (priority_queue.size() > 1) {
        shared_ptr<Node> left_node = priority_queue.top();
        priority_queue.pop();
        shared_ptr<Node> right_node = priority_queue.top();
        priority_queue.pop();
        priority_queue.push(make_shared<Node>(Node{left_node->frequency + right_node->frequency, '\0', left_node, right_node}));
    }

    return priority_queue.top();
}

/**
 * @brief Traverse the Huffman tree to assign bit strings to symbols.
 * @param node const shared_ptr<Node>& Current node visited by the recursive call.
 * @param codeword const string& Bit string built so far.
 * @param codeword_dict unordered_map<char, string>& Mapping from symbol to Huffman codeword.
 * @return void This function updates codeword_dict and does not return a value.
 */
void dfs_traversal(const shared_ptr<Node>& node,
                   const string& codeword,
                   unordered_map<char, string>& codeword_dict) {
    if (node->is_leaf()) {
        codeword_dict[node->symbol] = codeword.empty() ? "0" : codeword;
        return;
    }
    dfs_traversal(node->left, codeword + "0", codeword_dict);
    dfs_traversal(node->right, codeword + "1", codeword_dict);
}

/**
 * @brief Return the Huffman codeword for each symbol.
 * @param root_node const shared_ptr<Node>& Root of the Huffman tree.
 * @return unordered_map<char, string> Mapping from symbol to Huffman codeword.
 */
unordered_map<char, string> get_codewords(const shared_ptr<Node>& root_node) {
    unordered_map<char, string> codeword_dict;
    dfs_traversal(root_node, "", codeword_dict);
    return codeword_dict;
}

/**
 * @brief Encode a string using the supplied Huffman codewords.
 * @param input_string const string& Text to encode.
 * @param codewords const unordered_map<char, string>& Mapping from symbol to Huffman codeword.
 * @return string Bit string produced by Huffman encoding.
 */
string huffman_encode(const string& input_string, const unordered_map<char, string>& codewords) {
    string encoded;
    for (char symbol : input_string) {
        encoded += codewords.at(symbol);
    }
    return encoded;
}

/**
 * @brief Decode a Huffman bit string back into text.
 * @param encoded_string const string& Bit string produced by Huffman encoding.
 * @param root_node const shared_ptr<Node>& Root of the Huffman tree.
 * @return string Decoded plain-text string.
 */
string huffman_decode(const string& encoded_string, const shared_ptr<Node>& root_node) {
    string decoded_string;
    shared_ptr<Node> current_node = root_node;

    for (char bit : encoded_string) {
        current_node = bit == '0' ? current_node->left : current_node->right;
        if (current_node->is_leaf()) {
            decoded_string.push_back(current_node->symbol);
            current_node = root_node;
        }
    }

    return decoded_string;
}

/**
 * @brief Run the Huffman-coding demonstration.
 * @return int Exit status code returned to the operating system.
 */
int main() {
    vector<char> alphabet = {'A', 'B', 'C', 'D', 'E'};
    unordered_map<char, int> frequencies = {{'A', 1}, {'B', 1}, {'C', 1}, {'D', 1}, {'E', 12}};
    string input_string = "ABCDEABCDEABCDEE";

    shared_ptr<Node> root_node = build_huffman_tree(alphabet, frequencies);
    unordered_map<char, string> codewords = get_codewords(root_node);
    string encoded_string = huffman_encode(input_string, codewords);
    string decoded_string = huffman_decode(encoded_string, root_node);

    cout << "Codewords:\n";
    for (const auto& [symbol, codeword] : codewords) {
        cout << symbol << " -> " << codeword << '\n';
    }
    cout << "Encoded string: " << encoded_string << '\n';
    cout << "Decoded string: " << decoded_string << '\n';
    return 0;
}
