#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * @brief Build the bad-character shift table used by the pattern matcher.
 * @param pattern const string& The pattern searched for in the text.
 * @return unordered_map<char, int> The value produced by this function.
 */
unordered_map<char, int> badCharTable(const string& pattern) {
    unordered_map<char, int> table;
    int n = static_cast<int>(pattern.size());
    for (int index = 0; index < n - 1; ++index) {
        table[pattern[index]] = n - index - 1;
    }
    return table;
}

/**
 * @brief Return all positions where the pattern appears in the text.
 * @param text const string& The text or string processed by the function.
 * @param pattern const string& The pattern searched for in the text.
 * @return vector<int> The vector produced by the algorithm.
 */
vector<int> find_matches(const string& text, const string& pattern) {
    unordered_map<char, int> table = badCharTable(pattern);
    vector<int> matches;
    int m = static_cast<int>(text.size());
    int n = static_cast<int>(pattern.size());
    int i = 0;

    while (i <= m - n) {
        int j = n - 1;
        while (j >= 0 && pattern[j] == text[i + j]) {
            --j;
        }
        if (j < 0) {
            matches.push_back(i);
            i += n;
        } else {
            char mismatch = text[i + j];
            auto it = table.find(mismatch);
            i += it != table.end() ? it->second : n;
        }
    }
    return matches;
}

/**
 * @brief Return the LCS length and one longest common subsequence.
 * @param left const string& The left-side data or left boundary used by the algorithm.
 * @param right const string& The right-side data or right boundary used by the algorithm.
 * @return pair<int, string> The pair of values produced by the algorithm.
 */
pair<int, string> lcs(const string& left, const string& right) {
    vector<vector<int>> table(left.size() + 1, vector<int>(right.size() + 1, 0));
    for (size_t i = 1; i <= left.size(); ++i) {
        for (size_t j = 1; j <= right.size(); ++j) {
            if (left[i - 1] == right[j - 1]) table[i][j] = table[i - 1][j - 1] + 1;
            else table[i][j] = max(table[i - 1][j], table[i][j - 1]);
        }
    }

    string sequence;
    size_t i = left.size();
    size_t j = right.size();
    while (i > 0 && j > 0) {
        if (left[i - 1] == right[j - 1]) {
            sequence.push_back(left[i - 1]);
            --i;
            --j;
        } else if (table[i - 1][j] >= table[i][j - 1]) {
            --i;
        } else {
            --j;
        }
    }
    reverse(sequence.begin(), sequence.end());
    return {table[left.size()][right.size()], sequence};
}

/**
 * @brief Return the edit distance between two strings.
 * @param left const string& The left-side data or left boundary used by the algorithm.
 * @param right const string& The right-side data or right boundary used by the algorithm.
 * @return int The integer result produced by the algorithm.
 */
int editDistDP(const string& left, const string& right) {
    vector<vector<int>> table(left.size() + 1, vector<int>(right.size() + 1, 0));
    for (size_t i = 0; i <= left.size(); ++i) table[i][0] = static_cast<int>(i);
    for (size_t j = 0; j <= right.size(); ++j) table[0][j] = static_cast<int>(j);
    for (size_t i = 1; i <= left.size(); ++i) {
        for (size_t j = 1; j <= right.size(); ++j) {
            if (left[i - 1] == right[j - 1]) table[i][j] = table[i - 1][j - 1];
            else table[i][j] = 1 + min({table[i][j - 1], table[i - 1][j], table[i - 1][j - 1]});
        }
    }
    return table[left.size()][right.size()];
}

/**
 * @brief Run the small demonstration for this teaching example.
 * @return int The integer result produced by the algorithm.
 */
int main() {
    auto matches = find_matches("BESS_KNEW_ABOUT_BAOBABS", "BAOBAB");
    cout << "Pattern matches at indices: ";
    for (int match : matches) cout << match << ' ';
    cout << '\n';

    auto [length, sequence] = lcs("intention", "execution");
    cout << "LCS length: " << length << ", sequence: " << sequence << '\n';
    cout << "Edit distance: " << editDistDP("intention", "execution") << '\n';
    return 0;
}
