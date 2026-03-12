/**
 * @file prob3.cpp
 * @brief C++ version of the edit-distance example.
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * @brief Return the edit distance between two strings using dynamic programming.
 * @param str1 const string& First input string.
 * @param str2 const string& Second input string.
 * @return int Minimum number of insertions, deletions, and replacements required to turn str1 into str2.
 */
int editDistDP(const string& str1, const string& str2) {
    int m = static_cast<int>(str1.size());
    int n = static_cast<int>(str2.size());
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i == 0) {
                dp[i][j] = j;
            } else if (j == 0) {
                dp[i][j] = i;
            } else if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + min({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]});
            }
        }
    }
    return dp[m][n];
}

/**
 * @brief Run the edit-distance demonstration.
 * @return int Exit status code returned to the operating system.
 */
int main() {
    cout << "number of edit operation is: " << editDistDP("intention", "execution") << '\n';
    return 0;
}
