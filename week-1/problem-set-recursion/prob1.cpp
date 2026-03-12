/**
 * @file prob1.cpp
 * @brief C++ version of the recursive factorial example.
 */

#include <iostream>

using namespace std;

/**
 * @brief Return n factorial using recursion.
 * @param n int Non-negative integer whose factorial should be computed.
 * @return int Factorial of n.
 */
int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}

/**
 * @brief Run the factorial demonstration.
 * @return int Exit status code returned to the operating system.
 */
int main() {
    cout << factorial(5) << '\n';
    return 0;
}
