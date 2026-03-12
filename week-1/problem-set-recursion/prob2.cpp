/**
 * @file prob2.cpp
 * @brief C++ version of the recursive maximum-search example.
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Return the largest value in a list using recursion.
 * @param numbers const vector<int>& Input list of integers.
 * @param index size_t Current position examined by the recursive call.
 * @return int Largest value found from index to the end of the list.
 */
int find_max(const vector<int>& numbers, size_t index = 0) {
    if (index + 1 == numbers.size()) {
        return numbers[index];
    }
    int max_val = find_max(numbers, index + 1);
    return max(numbers[index], max_val);
}

/**
 * @brief Run the recursive maximum-search demonstration.
 * @return int Exit status code returned to the operating system.
 */
int main() {
    vector<int> numbers = {5, 10, 3, 8, 1};
    cout << find_max(numbers) << '\n';
    return 0;
}
