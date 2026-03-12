/**
 * @file prob3.cpp
 * @brief C++ version of the alternating-disks example.
 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Group identical disks together by swapping neighbouring positions.
 * @param disks vector<char> Disk labels where 'D' and 'L' alternate in the starting arrangement.
 * @return vector<char> Disk labels after the grouping process finishes.
 */
vector<char> alternating_disks(vector<char> disks) {
    int n = static_cast<int>(disks.size()) / 2;
    while (true) {
        bool swapped = false;
        for (int i = 0; i < n * 2 - 1; ++i) {
            if (disks[i] < disks[i + 1]) {
                swap(disks[i], disks[i + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
    return disks;
}

/**
 * @brief Run the alternating-disks demonstration.
 * @return int Exit status code returned to the operating system.
 */
int main() {
    vector<char> disks = {'D', 'L', 'D', 'L', 'D', 'L', 'D', 'L'};
    vector<char> solved_disks = alternating_disks(disks);
    for (char disk : solved_disks) {
        cout << disk << ' ';
    }
    cout << '\n';
    return 0;
}
