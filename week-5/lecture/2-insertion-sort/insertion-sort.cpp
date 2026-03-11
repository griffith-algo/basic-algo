#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Sort the list in ascending order using insertion sort.
 * @param values vector<int>& The vector of values processed by the function.
 * @return void This function updates data or prints results and does not return a value.
 */
void insertionSort(vector<int>& values) {
    for (size_t step = 1; step < values.size(); ++step) {
        int key = values[step];
        int j = static_cast<int>(step) - 1;
        while (j >= 0 && key < values[j]) {
            values[j + 1] = values[j];
            --j;
        }
        values[j + 1] = key;
        for (int value : values) cout << value << ' ';
        cout << '\n';
    }
}

/**
 * @brief Run the small demonstration for this teaching example.
 * @return int The integer result produced by the algorithm.
 */
int main() {
    vector<int> data = {6, 5, 3, 1, 8, 7, 2, 4};
    insertionSort(data);
    return 0;
}
