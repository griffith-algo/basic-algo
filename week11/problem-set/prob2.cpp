/**
 * @file prob2.cpp
 * @brief C++ version of the longest-common-subsequence example.
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

/**
 * @brief Return the length and one example of the longest common subsequence.
 * @param x const string& First input string.
 * @param y const string& Second input string.
 * @return pair<int, string> Pair containing the LCS length and one valid subsequence.
 */
pair<int, string> lcs(const string& x, const string& y) {
    int m = static_cast<int>(x.size());
    int n = static_cast<int>(y.size());
    vector<vector<int>> table(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (x[i - 1] == y[j - 1]) {
                table[i][j] = table[i - 1][j - 1] + 1;
            } else {
                table[i][j] = max(table[i - 1][j], table[i][j - 1]);
            }
        }
    }

    int i = m;
    int j = n;
    string characters;
    while (i > 0 && j > 0) {
        if (x[i - 1] == y[j - 1]) {
            characters.push_back(x[i - 1]);
            --i;
            --j;
        } else if (table[i - 1][j] >= table[i][j - 1]) {
            --i;
        } else {
            --j;
        }
    }
    reverse(characters.begin(), characters.end());
    return {table[m][n], characters};
}

/**
 * @brief Run the LCS demonstration.
 * @return int Exit status code returned to the operating system.
 */
int main() {
    pair<int, string> result = lcs("intention", "execution");
    cout << "LCS: (" << result.first << ", " << result.second << ")\n";
    return 0;
}
