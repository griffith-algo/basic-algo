/**
 * @file prob3.cpp
 * @brief C++ version of the recursive string-reversal example.
 */

#include <iostream>
#include <string>

using namespace std;

/**
 * @brief Return a reversed copy of the input string.
 * @param text const string& Original text to reverse.
 * @return string New string containing the characters of text in reverse order.
 */
string reverse_string(const string& text) {
    if (text.size() <= 1) {
        return text;
    }
    return reverse_string(text.substr(1)) + text[0];
}

/**
 * @brief Reverse a mutable string in place.
 * @param text string& String whose characters will be swapped in place.
 * @param left int Left index of the current recursive range.
 * @param right int Right index of the current recursive range.
 * @return string Updated string after the recursive swaps finish.
 */
string reverse_inplace(string& text, int left = 0, int right = -1) {
    if (right == -1) {
        right = static_cast<int>(text.size()) - 1;
    }
    if (left >= right) {
        return text;
    }

    swap(text[left], text[right]);
    return reverse_inplace(text, left + 1, right - 1);
}

/**
 * @brief Run the string-reversal demonstration.
 * @return int Exit status code returned to the operating system.
 */
int main() {
    string text = "hello world";
    string characters = text;

    cout << "Reversed copy: " << reverse_string(text) << '\n';
    cout << "Reversed in place: " << reverse_inplace(characters) << '\n';
    return 0;
}
