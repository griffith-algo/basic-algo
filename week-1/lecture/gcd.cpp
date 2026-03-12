/**
 * @file gcd.cpp
 * @brief C++ version of the recursive Euclid algorithm example.
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/**
 * @brief Compute the greatest common divisor of two integers.
 * @param m int First integer. The function treats negative values by using their absolute value.
 * @param n int Second integer. The function repeatedly replaces the larger value with the remainder.
 * @return int Greatest common divisor of m and n.
 */
int gcd(int m, int n) {
    m = abs(m);
    n = abs(n);

    if (m < n) {
        swap(m, n);
    }
    if (n == 0) {
        return m;
    }
    return gcd(n, m % n);
}

/**
 * @brief Run a small demonstration of the gcd function.
 * @return int Exit status code returned to the operating system.
 */
int main() {
    int m = 60;
    int n = 24;
    cout << "gcd(" << m << ", " << n << ") = " << gcd(m, n) << '\n';
    return 0;
}
