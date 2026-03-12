/**
 * @file two_sum_naive.cpp
 * @brief C++ version of the nested-loop two-sum example.
 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Return the indices of two numbers whose sum equals the target.
 * @param nums const vector<int>& Input list of integers. Each element has type int.
 * @param target int Desired total produced by adding two values from nums.
 * @return vector<int> Two indices when a solution exists, otherwise an empty vector.
 */
vector<int> two_sum(const vector<int>& nums, int target) {
    for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
        for (int j = i + 1; j < static_cast<int>(nums.size()); ++j) {
            if (nums[i] + nums[j] == target) {
                return {i, j};
            }
        }
    }
    return {};
}

/**
 * @brief Print a vector of integers in bracket form.
 * @param values const vector<int>& Vector to print. Each element has type int.
 * @return void This helper only prints data and does not return a value.
 */
void print_vector(const vector<int>& values) {
    cout << '[';
    for (size_t index = 0; index < values.size(); ++index) {
        cout << values[index];
        if (index + 1 != values.size()) {
            cout << ", ";
        }
    }
    cout << ']';
}

/**
 * @brief Run the two-sum demonstration.
 * @return int Exit status code returned to the operating system.
 */
int main() {
    vector<int> result = two_sum({2, 7, 11, 15}, 9);
    print_vector(result);
    cout << '\n';
    return 0;
}
