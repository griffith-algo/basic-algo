/**
 * @file prob2.cpp
 * @brief C++ version of the locker-toggling puzzle.
 */

#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Simulate every locker toggle exactly as stated in the puzzle.
 * @param n int Number of lockers and also number of students making passes.
 * @return vector<bool> Locker states where true means open and false means closed.
 */
vector<bool> toggle_lockers_from_scratch(int n) {
    vector<bool> lockers(n, false);

    for (int student = 1; student <= n; ++student) {
        for (int locker = student; locker <= n; locker += student) {
            lockers[locker - 1] = !lockers[locker - 1];
        }
    }

    return lockers;
}

/**
 * @brief Use the perfect-square observation to find the lockers that remain open.
 * @param n int Number of lockers in the puzzle.
 * @return vector<bool> Locker states where true means open and false means closed.
 */
vector<bool> toggle_lockers(int n) {
    vector<bool> lockers(n, false);
    for (int value = 1; value <= static_cast<int>(sqrt(n)); ++value) {
        lockers[value * value - 1] = true;
    }
    return lockers;
}

/**
 * @brief Print the open and closed locker numbers.
 * @param lockers const vector<bool>& Locker-state array produced by one of the algorithms.
 * @return void This helper only prints data and does not return a value.
 */
void print_results(const vector<bool>& lockers) {
    vector<int> opened;
    vector<int> closed;

    for (size_t index = 0; index < lockers.size(); ++index) {
        if (lockers[index]) {
            opened.push_back(static_cast<int>(index) + 1);
        } else {
            closed.push_back(static_cast<int>(index) + 1);
        }
    }

    cout << "Opened lockers: ";
    for (int locker : opened) {
        cout << locker << ' ';
    }
    cout << "\nClosed lockers: ";
    for (int locker : closed) {
        cout << locker << ' ';
    }
    cout << "\nNumber of opened lockers: " << opened.size() << '\n';
}

/**
 * @brief Run the locker-toggling demonstration.
 * @return int Exit status code returned to the operating system.
 */
int main() {
    int n = 20;
    vector<bool> toggled_lockers = toggle_lockers_from_scratch(n);
    print_results(toggled_lockers);
    return 0;
}
