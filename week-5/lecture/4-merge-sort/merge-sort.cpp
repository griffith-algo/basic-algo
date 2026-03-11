#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Merge two sorted halves into a single sorted result.
 * @param left_half const vector<int>& The sorted left half used during merging.
 * @param right_half const vector<int>& The sorted right half used during merging.
 * @return vector<int> The vector produced by the algorithm.
 */
vector<int> merge(const vector<int>& left_half, const vector<int>& right_half) {
    vector<int> merged;
    size_t left = 0;
    size_t right = 0;
    while (left < left_half.size() && right < right_half.size()) {
        if (left_half[left] <= right_half[right]) {
            merged.push_back(left_half[left++]);
        } else {
            merged.push_back(right_half[right++]);
        }
    }
    merged.insert(merged.end(), left_half.begin() + static_cast<long>(left), left_half.end());
    merged.insert(merged.end(), right_half.begin() + static_cast<long>(right), right_half.end());
    return merged;
}

/**
 * @brief Sort the list in ascending order using merge sort.
 * @param values const vector<int>& The vector of values processed by the function.
 * @return vector<int> The vector produced by the algorithm.
 */
vector<int> mergeSort(const vector<int>& values) {
    if (values.size() <= 1) return values;
    size_t middle = values.size() / 2;
    vector<int> left_half(values.begin(), values.begin() + static_cast<long>(middle));
    vector<int> right_half(values.begin() + static_cast<long>(middle), values.end());
    vector<int> merged = merge(mergeSort(left_half), mergeSort(right_half));
    for (int value : merged) cout << value << ' ';
    cout << '\n';
    return merged;
}

/**
 * @brief Run the small demonstration for this teaching example.
 * @return int The integer result produced by the algorithm.
 */
int main() {
    vector<int> data = {6, 5, 3, 1, 8, 7, 2, 4};
    vector<int> sorted = mergeSort(data);
    cout << "Sorted array: ";
    for (int value : sorted) cout << value << ' ';
    cout << '\n';
    return 0;
}
