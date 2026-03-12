/**
 * @file prob8.cpp
 * @brief C++ version of the deletion examples for unsorted and sorted arrays.
 */

#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

/**
 * @brief Delete one element in constant time by swapping it with the last value.
 * @param values vector<int>& Unsorted list of integers that will be modified in place.
 * @param index size_t Position of the element to remove.
 * @return vector<int> Copy of the updated list after the deletion.
 */
vector<int> delete_element(vector<int>& values, size_t index) {
    if (index >= values.size()) {
        throw out_of_range("Index out of range");
    }

    swap(values[index], values.back());
    values.pop_back();
    return values;
}

class SortedArray {
public:
    /**
     * @brief Store sorted values and a matching deletion-marker array.
     * @param values vector<int> Sorted list of integers managed by the object.
     */
    explicit SortedArray(vector<int> values) : values_(move(values)), deleted_(values_.size(), false) {}

    /**
     * @brief Mark one position as deleted without physically removing it.
     * @param index size_t Position to mark as deleted.
     * @return void This method updates internal state and does not return a value.
     */
    void delete_index(size_t index) {
        if (index >= values_.size()) {
            throw out_of_range("Index out of range");
        }
        deleted_[index] = true;
    }

    /**
     * @brief Search for a target value while skipping lazily deleted positions.
     * @param target int Value to search for in the sorted array.
     * @return int Index of the target if it is still active, otherwise -1.
     */
    int search(int target) const {
        int left = 0;
        int right = static_cast<int>(values_.size()) - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            int active_mid = nearest_active_index(mid, left, right);
            if (active_mid == -1) {
                return -1;
            }
            if (values_[active_mid] < target) {
                left = active_mid + 1;
            } else if (values_[active_mid] > target) {
                right = active_mid - 1;
            } else {
                return active_mid;
            }
        }

        return -1;
    }

    /**
     * @brief Count how many positions are still active.
     * @return size_t Number of entries that have not been deleted.
     */
    size_t active_count() const {
        size_t count = 0;
        for (bool flag : deleted_) {
            if (!flag) {
                ++count;
            }
        }
        return count;
    }

    /**
     * @brief Return the active values as a new vector.
     * @return vector<int> Copy of the values whose deletion marker is false.
     */
    vector<int> active_values() const {
        vector<int> result;
        for (size_t index = 0; index < values_.size(); ++index) {
            if (!deleted_[index]) {
                result.push_back(values_[index]);
            }
        }
        return result;
    }

private:
    /**
     * @brief Find the nearest index around mid that has not been lazily deleted.
     * @param mid int Middle index of the current binary-search range.
     * @param left int Left boundary of the current binary-search range.
     * @param right int Right boundary of the current binary-search range.
     * @return int Closest active index, or -1 when no active position exists in the range.
     */
    int nearest_active_index(int mid, int left, int right) const {
        int offset = 0;
        while (mid - offset >= left || mid + offset <= right) {
            int left_candidate = mid - offset;
            int right_candidate = mid + offset;

            if (left_candidate >= left && !deleted_[left_candidate]) {
                return left_candidate;
            }
            if (right_candidate <= right && !deleted_[right_candidate]) {
                return right_candidate;
            }
            ++offset;
        }
        return -1;
    }

    vector<int> values_;
    vector<bool> deleted_;
};

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
 * @brief Run the deletion demonstrations.
 * @return int Exit status code returned to the operating system.
 */
int main() {
    vector<int> values = {1, 2, 3, 4, 5};
    size_t delete_index_value = 2;

    vector<int> unsorted_copy = values;
    cout << "Delete from an unsorted list: ";
    print_vector(delete_element(unsorted_copy, delete_index_value));
    cout << '\n';

    SortedArray sorted_array(values);
    sorted_array.delete_index(delete_index_value);
    cout << "Number of active values: " << sorted_array.active_count() << '\n';
    cout << "Active values: ";
    print_vector(sorted_array.active_values());
    cout << "\nIndex of 4: " << sorted_array.search(4) << '\n';
    return 0;
}
