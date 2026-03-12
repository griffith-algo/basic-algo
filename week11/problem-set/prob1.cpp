/**
 * @file prob1.cpp
 * @brief C++ version of the bad-character pattern-matching example.
 */

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * @brief Build the bad-character shift table used by the pattern matcher.
 * @param pattern_string const string& Pattern searched for in the text.
 * @return unordered_map<char, int> Map from character to shift distance.
 */
unordered_map<char, int> badCharTable(const string& pattern_string) {
    int n = static_cast<int>(pattern_string.size());
    unordered_map<char, int> bad_char_table;

    for (int index = 0; index < n; ++index) {
        if (index != n - 1) {
            bad_char_table[pattern_string[index]] = n - index - 1;
        }
    }
    bad_char_table['*'] = n;
    return bad_char_table;
}

/**
 * @brief Search the text for every occurrence of the pattern.
 * @param text const string& Text in which the pattern is searched.
 * @param pattern_string const string& Pattern to locate.
 * @return vector<int> Starting indices where the pattern appears.
 */
vector<int> find_matches(const string& text, const string& pattern_string) {
    unordered_map<char, int> bad_char_table = badCharTable(pattern_string);
    int m = static_cast<int>(text.size());
    int n = static_cast<int>(pattern_string.size());
    int i = 0;
    vector<int> result;

    while (i < m - n + 1) {
        bool mismatch_found = false;
        for (int index = 0; index < n; ++index) {
            char pattern_character = pattern_string[n - index - 1];
            char text_character = text[i + n - index - 1];
            if (pattern_character != text_character) {
                auto position = bad_char_table.find(text_character);
                i += position != bad_char_table.end() ? position->second : bad_char_table['*'];
                mismatch_found = true;
                break;
            }
        }
        if (!mismatch_found) {
            result.push_back(i);
            char shift_char = text[i + n - 1];
            auto position = bad_char_table.find(shift_char);
            i += position != bad_char_table.end() ? position->second : bad_char_table['*'];
        }
    }

    return result;
}

/**
 * @brief Run the pattern-matching demonstration.
 * @return int Exit status code returned to the operating system.
 */
int main() {
    vector<int> matches = find_matches("BESS_KNEW_ABOUT_BAOBABS", "BAOBAB");
    for (int match : matches) {
        cout << match << ' ';
    }
    cout << '\n';
    return 0;
}
