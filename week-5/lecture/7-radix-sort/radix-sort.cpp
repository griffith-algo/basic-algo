#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Sort the values by one digit position as part of radix sort.
 * @param values vector<int>& The vector of values processed by the function.
 * @param place int The place value used by this function.
 * @return void This function updates data or prints results and does not return a value.
 */
void countingSort(vector<int>& values, int place) {
    vector<int> output(values.size(), 0);
    vector<int> count(10, 0);

    for (int value : values) {
        ++count[(value / place) % 10];
    }
    for (size_t i = 1; i < count.size(); ++i) {
        count[i] += count[i - 1];
    }
    for (int index = static_cast<int>(values.size()) - 1; index >= 0; --index) {
        int digit = (values[index] / place) % 10;
        output[count[digit] - 1] = values[index];
        --count[digit];
    }
    values = output;
}

/**
 * @brief Sort non-negative integers using radix sort.
 * @param values vector<int>& The vector of values processed by the function.
 * @return void This function updates data or prints results and does not return a value.
 */
void radixSort(vector<int>& values) {
    int maximum = *max_element(values.begin(), values.end());
    for (int place = 1; maximum / place > 0; place *= 10) {
        countingSort(values, place);
    }
}

/**
 * @brief Run the small demonstration for this teaching example.
 * @return int The integer result produced by the algorithm.
 */
int main() {
    vector<int> data = {121, 432, 564, 23, 1, 45, 788};
    radixSort(data);
    for (int value : data) cout << value << ' ';
    cout << '\n';
    return 0;
}
