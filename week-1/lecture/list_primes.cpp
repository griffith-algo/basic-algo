/**
 * @file list_primes.cpp
 * @brief C++ version of the prime-listing and timing example.
 */

#include <chrono>
#include <iostream>
#include <vector>

using namespace std;
using Clock = chrono::high_resolution_clock;

/**
 * @brief Return all prime numbers from 2 up to n using trial division.
 * @param n int Upper limit of the search. The function checks every integer from 2 to n.
 * @return vector<int> Prime numbers found up to and including n.
 */
vector<int> get_primes(int n) {
    vector<int> primes;

    for (int num = 2; num <= n; ++num) {
        bool is_prime = true;
        for (int factor = 2; factor * factor <= num; ++factor) {
            if (num % factor == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime) {
            primes.push_back(num);
        }
    }

    return primes;
}

/**
 * @brief Return all prime numbers from 2 up to n using the sieve of Eratosthenes.
 * @param n int Upper limit of the search. The function marks multiples of smaller primes.
 * @return vector<int> Prime numbers found up to and including n.
 */
vector<int> sieve_of_eratosthenes(int n) {
    vector<bool> prime(n + 1, true);
    if (n >= 0) {
        prime[0] = false;
    }
    if (n >= 1) {
        prime[1] = false;
    }

    for (int p = 2; p * p <= n; ++p) {
        if (prime[p]) {
            for (int multiple = p * 2; multiple <= n; multiple += p) {
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
 * @brief Measure and print the runtime of the two prime-generation methods.
 * @return int Exit status code returned to the operating system.
 */
int main() {
    int n = 10000;

    auto trial_start = Clock::now();
    vector<int> trial_primes = get_primes(n);
    auto trial_end = Clock::now();

    auto sieve_start = Clock::now();
    vector<int> sieve_primes = sieve_of_eratosthenes(n);
    auto sieve_end = Clock::now();

    chrono::duration<double> trial_time = trial_end - trial_start;
    chrono::duration<double> sieve_time = sieve_end - sieve_start;

    cout << "Trial division found " << trial_primes.size() << " primes in " << trial_time.count() << " seconds\n";
    cout << "Sieve found " << sieve_primes.size() << " primes in " << sieve_time.count() << " seconds\n";
    return 0;
}
