/**
 * @file prob5.cpp
 * @brief C++ version of the minimum-distance example.
 */

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

/**
 * @brief Return the smallest distance between any two values in the list.
 * @param values vector<int> Copy of the input list. The function sorts this copy before comparing neighbours.
 * @return int Minimum absolute difference between any two values.
 */
int min_distance(vector<int> values) {
    sort(values.begin(), values.end());
    int dmin = numeric_limits<int>::max();

    for (size_t index = 1; index < values.size(); ++index) {
        int difference = abs(values[index] - values[index - 1]);
        if (difference < dmin) {
            dmin = difference;
        }
    }

    return dmin;
}

/**
 * @brief Run the minimum-distance demonstration.
 * @return int Exit status code returned to the operating system.
 */
int main() {
    vector<int> values = {2, 4, 8, 3, 10};
    cout << min_distance(values) << '\n';
    return 0;
}
