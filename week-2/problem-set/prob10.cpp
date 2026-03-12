/**
 * @file prob10.cpp
 * @brief C++ version of the iterative Tower of Hanoi example.
 */

#include <iostream>
#include <stack>
#include <tuple>

using namespace std;

/**
 * @brief Solve the Tower of Hanoi problem iteratively with an explicit stack.
 * @param n int Number of disks in the puzzle.
 * @param src char Name of the source peg.
 * @param dest char Name of the destination peg.
 * @param aux char Name of the auxiliary peg.
 * @return void This function prints each move and does not return a value.
 */
void tower_of_hanoi(int n, char src, char dest, char aux) {
    stack<tuple<int, char, char, char>> work;
    work.push({n, src, dest, aux});

    while (!work.empty()) {
        auto [disks, source, destination, helper] = work.top();
        work.pop();

        if (disks == 1) {
            cout << "Move disk from " << source << " to " << destination << '\n';
        } else {
            work.push({disks - 1, helper, destination, source});
            work.push({1, source, destination, helper});
            work.push({disks - 1, source, helper, destination});
        }
    }
}

/**
 * @brief Run the iterative Tower of Hanoi demonstration.
 * @return int Exit status code returned to the operating system.
 */
int main() {
    tower_of_hanoi(3, 'A', 'C', 'B');
    return 0;
}
