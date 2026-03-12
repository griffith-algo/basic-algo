/**
 * @file prob1.cpp
 * @brief C++ version of the iterative and recursive Euclid comparison.
 */

#include <cstdlib>
#include <iostream>
#include <utility>

using namespace std;

/**
 * @brief Compute the gcd iteratively and count loop executions.
 * @param m int First integer used by Euclid's algorithm.
 * @param n int Second integer used by Euclid's algorithm.
 * @return pair<int, int> Pair containing the gcd and the number of loop iterations.
 */
pair<int, int> euclid_algorithm(int m, int n) {
    int count_exec = 0;
    m = abs(m);
    n = abs(n);

    if (m >= n) {
        while (n != 0) {
            int r = m % n;
            m = n;
            n = r;
            ++count_exec;
            cout << m << ' ' << n << '\n';
        }
        return {m, count_exec};
    }

    while (m != 0) {
        int r = n % m;
        n = m;
        m = r;
        ++count_exec;
        cout << m << ' ' << n << '\n';
    }
    return {n, count_exec};
}

/**
 * @brief Compute the gcd recursively and count recursive calls.
 * @param m int First integer used by Euclid's algorithm.
 * @param n int Second integer used by Euclid's algorithm.
 * @param count int Number of recursive steps counted so far.
 * @return pair<int, int> Pair containing the gcd and the final recursive-step count.
 */
pair<int, int> euclid(int m, int n, int count) {
    m = abs(m);
    n = abs(n);

    if (m < n) {
        ++count;
        cout << m << ' ' << n << '\n';
        swap(m, n);
    }
    if (n == 0) {
        return {m, count};
    }
    return euclid(n, m % n, count + 1);
}

/**
 * @brief Run the gcd-counting demonstration.
 * @return int Exit status code returned to the operating system.
 */
int main() {
    pair<int, int> result = euclid(24, 60, 0);
    cout << "GCD: " << result.first << '\n';
    cout << "Number of times: " << result.second << '\n';
    return 0;
}
