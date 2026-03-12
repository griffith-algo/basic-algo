/**
 * @file prob3.cpp
 * @brief C++ version of the memoised recurrence example.
 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Compute the recurrence value using memoization.
 * @param n int Position in the recurrence sequence.
 * @param memo vector<int>& Table that stores already computed values. A value of -1 means "not computed yet".
 * @return int Recurrence value F(n).
 */
int F(int n, vector<int>& memo) {
    if (n < 3) {
        return 1;
    }
    if (memo[n] == -1) {
        memo[n] = F(n - 1, memo) + F(n - 2, memo);
    }
    return memo[n];
}

/**
 * @brief Run the memoised recurrence demonstration.
 * @return int Exit status code returned to the operating system.
 */
int main() {
    int n = 10;
    vector<int> memo(n + 1, -1);
    cout << "The result of F(" << n << ") is: " << F(n, memo) << '\n';
    return 0;
}
