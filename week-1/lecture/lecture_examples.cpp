#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * @brief Compute the greatest common divisor using Euclid's algorithm.
 * @param m int The size value used by the function.
 * @param n int The size value or number of recursive steps used by the function.
 * @return int The integer result produced by the algorithm.
 */
int gcd_recursive(int m, int n) {
    m = abs(m);
    n = abs(n);
    if (m < n) {
        swap(m, n);
    }
    if (n == 0) {
        return m;
    }
    return gcd_recursive(n, m % n);
}

/**
 * @brief Print the moves needed to solve the Tower of Hanoi problem.
 * @param n int The size value or number of recursive steps used by the function.
 * @param source char The source peg, basket, or container used in the example.
 * @param target char The target peg, basket, or value used in the example.
 * @param auxiliary char The helper peg or container used in the example.
 * @return void This function updates data or prints results and does not return a value.
 */
void hanoi(int n, char source, char target, char auxiliary) {
    if (n == 0) {
        return;
    }
    hanoi(n - 1, source, auxiliary, target);
    cout << "Move disk " << n << " from " << source << " to " << target << '\n';
    hanoi(n - 1, auxiliary, target, source);
}

/**
 * @brief Return the prime numbers up to the given limit using trial division.
 * @param n int The size value or number of recursive steps used by the function.
 * @return vector<int> The vector produced by the algorithm.
 */
vector<int> get_primes(int n) {
    vector<int> primes;
    for (int value = 2; value <= n; ++value) {
        bool is_prime = true;
        for (int factor = 2; factor * factor <= value; ++factor) {
            if (value % factor == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime) {
            primes.push_back(value);
        }
    }
    return primes;
}

/**
 * @brief Return the prime numbers up to the given limit using the sieve method.
 * @param n int The size value or number of recursive steps used by the function.
 * @return vector<int> The vector produced by the algorithm.
 */
vector<int> sieve_of_eratosthenes(int n) {
    vector<bool> prime(n + 1, true);
    if (n >= 0) {
        prime[0] = false;
    }
    if (n >= 1) {
        prime[1] = false;
    }

    for (int value = 2; value * value <= n; ++value) {
        if (prime[value]) {
            for (int multiple = value * value; multiple <= n; multiple += value) {
                prime[multiple] = false;
            }
        }
    }

    vector<int> primes;
    for (int value = 2; value <= n; ++value) {
        if (prime[value]) {
            primes.push_back(value);
        }
    }
    return primes;
}

/**
 * @brief Sort the list in ascending order using selection sort.
 * @param values vector<int>& The vector of values processed by the function.
 * @return void This function updates data or prints results and does not return a value.
 */
void selection_sort(vector<int>& values) {
    for (size_t i = 0; i < values.size(); ++i) {
        size_t min_index = i;
        for (size_t j = i + 1; j < values.size(); ++j) {
            if (values[j] < values[min_index]) {
                min_index = j;
            }
        }
        swap(values[i], values[min_index]);
    }
}

/**
 * @brief Run the two sum step used in this example.
 * @param nums const vector<int>& The vector of numbers searched by the algorithm.
 * @param target int The target peg, basket, or value used in the example.
 * @return vector<int> The vector produced by the algorithm.
 */
vector<int> two_sum(const vector<int>& nums, int target) {
    unordered_map<int, int> seen;
    for (int index = 0; index < static_cast<int>(nums.size()); ++index) {
        int complement = target - nums[index];
        auto it = seen.find(complement);
        if (it != seen.end()) {
            return {it->second, index};
        }
        seen[nums[index]] = index;
    }
    return {};
}

/**
 * @brief Run the two sum naive step used in this example.
 * @param nums const vector<int>& The vector of numbers searched by the algorithm.
 * @param target int The target peg, basket, or value used in the example.
 * @return vector<int> The vector produced by the algorithm.
 */
vector<int> two_sum_naive(const vector<int>& nums, int target) {
    for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
        for (int j = i + 1; j < static_cast<int>(nums.size()); ++j) {
            if (nums[i] + nums[j] == target) {
                return {i, j};
            }
        }
    }
    return {};
}

template <typename T>
/**
 * @brief Print the vector in a beginner-friendly format.
 * @param values const vector<T>& The vector of values processed by the function.
 * @return void This function updates data or prints results and does not return a value.
 */
void print_vector(const vector<T>& values) {
    cout << '[';
    for (size_t i = 0; i < values.size(); ++i) {
        cout << values[i];
        if (i + 1 != values.size()) {
            cout << ", ";
        }
    }
    cout << ']';
}

/**
 * @brief Run the small demonstration for this teaching example.
 * @return int The integer result produced by the algorithm.
 */
int main() {
    cout << "gcd(60, 24) = " << gcd_recursive(60, 24) << "\n\n";

    cout << "Tower of Hanoi with 3 disks:\n";
    hanoi(3, 'A', 'C', 'B');
    cout << '\n';

    cout << "Primes up to 20 (trial division): ";
    print_vector(get_primes(20));
    cout << '\n';
    cout << "Primes up to 20 (sieve): ";
    print_vector(sieve_of_eratosthenes(20));
    cout << "\n\n";

    vector<int> values = {29, 10, 14, 37, 13};
    selection_sort(values);
    cout << "Selection sort result: ";
    print_vector(values);
    cout << "\n\n";

    vector<int> numbers = {2, 7, 11, 15};
    cout << "Two-sum with hashing: ";
    print_vector(two_sum(numbers, 9));
    cout << '\n';
    cout << "Two-sum naive: ";
    print_vector(two_sum_naive(numbers, 9));
    cout << '\n';
    return 0;
}
