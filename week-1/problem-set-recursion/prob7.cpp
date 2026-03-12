/**
 * @file prob7.cpp
 * @brief C++ version of the recursive character-replacement example.
 */

#include <iostream>
#include <string>

using namespace std;

/**
 * @brief Recursively replace every occurrence of one character with another.
 * @param text const string& Original text that may contain the character to replace.
 * @param from_char char Character that should be replaced.
 * @param to_char char Replacement character.
 * @return string New string after every matching character has been replaced.
 */
string replace_recursive(const string& text, char from_char, char to_char) {
    if (text.empty()) {
        return text;
    }

    if (text[0] == from_char) {
        return string(1, to_char) + replace_recursive(text.substr(1), from_char, to_char);
    }
    return string(1, text[0]) + replace_recursive(text.substr(1), from_char, to_char);
}

/**
 * @brief Run the recursive replacement demonstration.
 * @return int Exit status code returned to the operating system.
 */
int main() {
    string text = "steve";
    char from_char = 'e';
    char to_char = 'a';

    cout << replace_recursive(text, from_char, to_char) << '\n';
    return 0;
}
