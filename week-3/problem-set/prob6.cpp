/**
 * @file prob6.cpp
 * @brief C++ version of the dynamic-programming coin-count example.
 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Count the number of ways to make a target sum with unlimited coins.
 * @param coins const vector<int>& Coin denominations available to the algorithm.
 * @param n int Number of denominations from coins to use.
 * @param total int Target sum to build.
 * @return int Number of distinct combinations that produce total.
 */
int count_dynamic_programming(const vector<int>& coins, int n, int total) {
    vector<vector<int>> table(n + 1, vector<int>(total + 1, 0));

    for (int row = 0; row <= n; ++row) {
        table[row][0] = 1;
    }

    for (int coin_index = 1; coin_index <= n; ++coin_index) {
        int coin = coins[coin_index - 1];
        for (int amount = 1; amount <= total; ++amount) {
            int ways_without_coin = table[coin_index - 1][amount];
            int ways_with_coin = coin <= amount ? table[coin_index][amount - coin] : 0;
            table[coin_index][amount] = ways_without_coin + ways_with_coin;
        }
    }

    return table[n][total];
}

/**
 * @brief Run the coin-count demonstration.
 * @return int Exit status code returned to the operating system.
 */
int main() {
    cout << count_dynamic_programming({1, 2, 3}, 3, 4) << '\n';
    return 0;
}
