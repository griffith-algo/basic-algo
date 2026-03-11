#include <iostream>
#include <utility>
#include <vector>

using namespace std;

/**
 * @brief Sort the list in ascending order using bubble sort.
 * @param values vector<int>& The vector of values processed by the function.
 * @return void This function updates data or prints results and does not return a value.
 */
void bubbleSort(vector<int>& values) {
    for (size_t pass = 0; pass < values.size(); ++pass) {
        bool swapped = false;
        for (size_t i = 0; i + 1 < values.size() - pass; ++i) {
            if (values[i] > values[i + 1]) {
                swap(values[i], values[i + 1]);
                swapped = true;
            }
        }
        for (int value : values) cout << value << ' ';
        cout << '\n';
        if (!swapped) break;
    }
}

/**
 * @brief Run the small demonstration for this teaching example.
 * @return int The integer result produced by the algorithm.
 */
int main() {
    vector<int> data = {6, 5, 3, 1, 8, 7, 2, 4};
    bubbleSort(data);
    return 0;
}
