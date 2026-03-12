/**
 * @file prob9.cpp
 * @brief C++ version of the maximum coin-row example.
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Return the maximum value collectable from non-adjacent coins.
 * @param coins const vector<int>& Coin values arranged in a row.
 * @return int Maximum obtainable sum when adjacent coins cannot both be chosen.
 */
int max_coin_row(const vector<int>& coins) {
    int n = static_cast<int>(coins.size());
    vector<int> tm(n + 1, 0);
    tm[1] = coins[0];

    for (int i = 2; i <= n; ++i) {
        tm[i] = max(tm[i - 1], coins[i - 1] + tm[i - 2]);
    }
    return tm[n];
}

/**
 * @brief Run the maximum coin-row demonstration.
 * @return int Exit status code returned to the operating system.
 */
int main() {
    vector<int> coins = {5, 1, 2, 10, 6};
    cout << max_coin_row(coins) << '\n';
    return 0;
}
