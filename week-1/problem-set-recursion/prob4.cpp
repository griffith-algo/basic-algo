/**
 * @file prob4.cpp
 * @brief C++ version of the recursive rabbit-count example.
 */

#include <iostream>

using namespace std;

/**
 * @brief Return the number of rabbit pairs in the Fibonacci-style growth model.
 * @param n int Month or year number in the recurrence relation.
 * @return int Number of rabbit pairs predicted for step n.
 */
int rabbit_count(int n) {
    if (n == 1 || n == 2) {
        return 1;
    }
    return rabbit_count(n - 1) + rabbit_count(n - 2);
}

/**
 * @brief Run the rabbit-count demonstration.
 * @return int Exit status code returned to the operating system.
 */
int main() {
    int n = 6;
    cout << "Rabbit at the year: " << rabbit_count(n) << '\n';
    return 0;
}
