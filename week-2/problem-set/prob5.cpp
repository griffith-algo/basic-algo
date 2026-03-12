/**
 * @file prob5.cpp
 * @brief C++ version of the anagram example.
 */

#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>

using namespace std;

/**
 * @brief Return true when two words contain the same letters.
 * @param word1 string First text to compare.
 * @param word2 string Second text to compare.
 * @return bool True when the cleaned and sorted letters match, otherwise false.
 */
bool is_anagram(string word1, string word2) {
    string cleaned1;
    string cleaned2;

    for (char character : word1) {
        if (isalpha(static_cast<unsigned char>(character))) {
            cleaned1.push_back(static_cast<char>(tolower(static_cast<unsigned char>(character))));
        }
    }
    for (char character : word2) {
        if (isalpha(static_cast<unsigned char>(character))) {
            cleaned2.push_back(static_cast<char>(tolower(static_cast<unsigned char>(character))));
        }
    }

    sort(cleaned1.begin(), cleaned1.end());
    sort(cleaned2.begin(), cleaned2.end());
    return cleaned1 == cleaned2;
}

/**
 * @brief Run the anagram demonstrations.
 * @return int Exit status code returned to the operating system.
 */
int main() {
    cout << boolalpha << is_anagram("tea", "eat") << '\n';
    cout << is_anagram("silent", "listen") << '\n';
    cout << is_anagram("desserts", "stressed") << '\n';
    cout << is_anagram("hello", "world") << '\n';
    return 0;
}
