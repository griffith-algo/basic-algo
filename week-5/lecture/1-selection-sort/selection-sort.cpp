#include <iostream>
#include <utility>
#include <vector>

using namespace std;

/**
 * @brief Sort the list in ascending order using selection sort.
 * @param values vector<int>& The vector of values processed by the function.
 * @return void This function updates data or prints results and does not return a value.
 */
void selectionSort(vector<int>& values) {
    for (size_t step = 0; step < values.size(); ++step) {
        size_t min_index = step;
        for (size_t i = step + 1; i < values.size(); ++i) {
            if (values[i] < values[min_index]) {
                min_index = i;
            }
        }
        swap(values[step], values[min_index]);
        for (int value : values) cout << value << ' ';
        cout << '\n';
    }
}

/**
 * @brief Run the small demonstration for this teaching example.
 * @return int The integer result produced by the algorithm.
 */
int main() {
    vector<int> data = {-2, 45, 0, 11, -9, 3};
    selectionSort(data);
    return 0;
}
