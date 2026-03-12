/**
 * @file prob6.cpp
 * @brief C++ version of the recursive palindrome example.
 */

#include <cctype>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * @brief Remove spaces and punctuation so the palindrome test is easier to read.
 * @param text const string& Original text that may contain spaces or punctuation.
 * @return string Lowercase string containing only alphanumeric characters.
 */
string clean_text(const string& text) {
    string cleaned;
    for (char character : text) {
        if (isalnum(static_cast<unsigned char>(character))) {
            cleaned.push_back(static_cast<char>(tolower(static_cast<unsigned char>(character))));
        }
    }
    return cleaned;
}

/**
 * @brief Return true when the string reads the same forwards and backwards.
 * @param text const string& Cleaned text used for the recursive comparison.
 * @param length int Number of characters currently considered by the recursive call.
 * @return bool True when text is a palindrome, otherwise false.
 */
bool is_palindrome(const string& text, int length) {
    if (length <= 1) {
        return true;
    }
    if (text[0] != text[length - 1]) {
        return false;
    }
    return is_palindrome(text.substr(1, length - 2), length - 2);
}

/**
 * @brief Run the palindrome demonstrations.
 * @return int Exit status code returned to the operating system.
 */
int main() {
    vector<string> examples = {
        "racecar",
        "hello",
        "A man, a plan, a canal, Panama!"
    };

    for (const string& text : examples) {
        string cleaned = clean_text(text);
        cout << text << " -> " << boolalpha << is_palindrome(cleaned, static_cast<int>(cleaned.size())) << '\n';
    }
    return 0;
}
