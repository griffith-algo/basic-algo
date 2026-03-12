/**
 * @file prob4.cpp
 * @brief C++ version of the recursive power-of-two example.
 */

#include <iostream>

using namespace std;

/**
 * @brief Return 2 raised to the power n using recursion.
 * @param n int Exponent of 2.
 * @return int Value of 2^n.
 */
int power_of_two(int n) {
    if (n == 0) {
        return 1;
    }
    return 2 * power_of_two(n - 1);
}

/**
 * @brief Run the power-of-two demonstration.
 * @return int Exit status code returned to the operating system.
 */
int main() {
    cout << power_of_two(5) << '\n';
    return 0;
}
