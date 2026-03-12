/**
 * @file prob_10_shares.cpp
 * @brief C++ version of the grouped integer-division share calculation.
 */

#include <iostream>

using namespace std;

/**
 * @brief Sum the share counts for every day from 1 to n using grouped quotients.
 * @param n long long Number of days or items in the problem.
 * @return long long Total number of shares counted across all grouped day ranges.
 */
long long total_shares(long long n) {
    long long total = 0;
    long long i = 1;

    while (i <= n) {
        long long shares = n / i;
        long long last_day = n / shares;
        long long days_in_group = last_day - i + 1;
        total += shares * days_in_group;
        i = last_day + 1;
    }

    return total;
}

/**
 * @brief Run the grouped share-count demonstration.
 * @return int Exit status code returned to the operating system.
 */
int main() {
    cout << total_shares(10) << '\n';
    return 0;
}
