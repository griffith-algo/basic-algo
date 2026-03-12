/**
 * @file prob8.cpp
 * @brief C++ version of the chaining-hash-table distinctness example.
 */

#include <iostream>
#include <vector>

using namespace std;

class ChainingHashTable {
public:
    /**
     * @brief Create a simple chaining hash table.
     * @param size int Number of buckets to create. The bucket array stores vectors of int.
     */
    explicit ChainingHashTable(int size = 100) : size(size), table(size) {}

    /**
     * @brief Map a value to one bucket in the hash table.
     * @param value int Value to hash.
     * @return int Bucket index used for value.
     */
    int hash_function(int value) const {
        return value % 2;
    }

    /**
     * @brief Insert a value if it is not already present.
     * @param value int Value to insert.
     * @return bool True when the value was inserted, otherwise false when it was already present.
     */
    bool insert(int value) {
        int index = hash_function(value);
        cout << index << '\n';
        for (int stored : table[index]) {
            if (stored == value) {
                return false;
            }
        }
        table[index].push_back(value);
        return true;
    }

private:
    int size;
    vector<vector<int>> table;
};

/**
 * @brief Return true when a list contains no duplicate values.
 * @param lst const vector<int>& List of integers to test.
 * @return bool True when all values are distinct, otherwise false.
 */
bool is_distinct(const vector<int>& lst) {
    ChainingHashTable hash_table;
    for (int elem : lst) {
        if (!hash_table.insert(elem)) {
            return false;
        }
    }
    return true;
}

/**
 * @brief Run the distinctness demonstration.
 * @return int Exit status code returned to the operating system.
 */
int main() {
    vector<int> lst = {1, 11, 21, 31};
    cout << boolalpha << is_distinct(lst) << '\n';
    return 0;
}
