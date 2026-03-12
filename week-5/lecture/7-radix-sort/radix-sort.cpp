/**
 * @file radix-sort.cpp
 * @brief C++ version of the week 5 radix-sort lecture example.
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Sort values by one digit position as part of radix sort.
 * @param array vector<int>& List of non-negative integers to reorder in place.
 * @param place int Current digit place, such as 1 for ones or 10 for tens.
 * @return void This function updates array in place and does not return a value.
 */
void countingSort(vector<int>& array, int place) {
    vector<int> output(array.size(), 0);
    vector<int> count(10, 0);

    for (int value : array) {
        ++count[(value / place) % 10];
    }
    for (size_t i = 1; i < count.size(); ++i) {
        count[i] += count[i - 1];
    }
    for (int i = static_cast<int>(array.size()) - 1; i >= 0; --i) {
        int digit = (array[i] / place) % 10;
        output[count[digit] - 1] = array[i];
        --count[digit];
    }
    array = output;
}

/**
 * @brief Sort non-negative integers with radix sort.
 * @param array vector<int>& List of non-negative integers to sort in place.
 * @return void This function updates array in place and does not return a value.
 */
void radixSort(vector<int>& array) {
    int maximum = *max_element(array.begin(), array.end());
    for (int place = 1; maximum / place > 0; place *= 10) {
        countingSort(array, place);
    }
}

/**
 * @brief Run the radix-sort lecture example.
 * @return int Exit status code returned to the operating system.
 */
int main() {
    vector<int> data = {121, 432, 564, 23, 1, 45, 788};
    radixSort(data);
    for (int value : data) {
        cout << value << ' ';
    }
    cout << '\n';
    return 0;
}
