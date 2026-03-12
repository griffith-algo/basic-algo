/**
 * @file prob7.cpp
 * @brief C++ version of the greedy-change example.
 */

#include <iostream>
#include <map>
#include <vector>

using namespace std;

/**
 * @brief Choose coins greedily from largest denomination to smallest.
 * @param n int Target amount of money to make.
 * @param denominations const vector<int>& Coin denominations, typically given from largest to smallest.
 * @return map<int, int, greater<int>> Mapping from coin value to how many times it was used.
 */
map<int, int, greater<int>> greedy_change_with_denominations(int n, const vector<int>& denominations) {
    map<int, int, greater<int>> denominations_used;
    for (int denomination : denominations) {
        while (n >= denomination) {
            n -= denomination;
            ++denominations_used[denomination];
        }
    }
    return denominations_used;
}

/**
 * @brief Run the greedy-change demonstration.
 * @return int Exit status code returned to the operating system.
 */
int main() {
    vector<int> denominations = {9, 3, 2};
    int n = 11;
    map<int, int, greater<int>> denominations_used = greedy_change_with_denominations(n, denominations);
    for (const auto& [denomination, count] : denominations_used) {
        cout << denomination << " -> " << count << '\n';
    }
    return 0;
}
