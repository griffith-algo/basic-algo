/**
 * @file calculateShares_hints.cpp
 * @brief C++ version of the integer-division hints for the share problem.
 */

#include <iostream>

using namespace std;

/**
 * @brief Print every quotient n / i so students can observe repeated values.
 * @param n long long Number of days or items used in the share-calculation exercise.
 * @return void This function only prints data and does not return a value.
 */
void print_share_hints(long long n) {
    for (long long i = 1; i <= n; ++i) {
        long long quotient = n / i;
        cout << n << "//" << i << " = " << quotient << '\n';
    }
}

/**
 * @brief Print groups of consecutive days that have the same quotient.
 * @param n long long Number of days or items used in the share-calculation exercise.
 * @return void This function only prints data and does not return a value.
 */
void print_groups(long long n) {
    long long i = 1;
    while (i <= n) {
        long long quotient = n / i;
        long long last_day = n / quotient;
        cout << "Days " << i << " to " << last_day << " all give quotient " << quotient << '\n';
        i = last_day + 1;
    }
}

/**
 * @brief Run the quotient-hint demonstration.
 * @return int Exit status code returned to the operating system.
 */
int main() {
    long long n = 35;
    print_share_hints(n);
    cout << '\n';
    print_groups(n);
    return 0;
}
