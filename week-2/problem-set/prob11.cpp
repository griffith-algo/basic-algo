/**
 * @file prob11.cpp
 * @brief C++ version of the stock-span example.
 */

#include <chrono>
#include <iostream>
#include <vector>

using namespace std;
using Clock = chrono::high_resolution_clock;

/**
 * @brief Compute the stock span for each day.
 * @param prices const vector<int>& Daily stock prices.
 * @return vector<int> Span values where each entry counts consecutive earlier days with price less than or equal to the current day.
 */
vector<int> stock_span(const vector<int>& prices) {
    vector<int> stack_indices;
    vector<int> span;

    for (int i = 0; i < static_cast<int>(prices.size()); ++i) {
        int cur_span = 1;
        while (!stack_indices.empty() && prices[stack_indices.back()] <= prices[i]) {
            int prev_index = stack_indices.back();
            stack_indices.pop_back();
            cur_span += span[prev_index];
        }
        span.push_back(cur_span);
        stack_indices.push_back(i);
    }

    return span;
}

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
 * @brief Run the stock-span demonstration and print the runtime.
 * @return int Exit status code returned to the operating system.
 */
int main() {
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};

    auto start_time = Clock::now();
    vector<int> span = stock_span(prices);
    auto end_time = Clock::now();

    print_vector(span);
    cout << '\n';
    chrono::duration<double> elapsed = end_time - start_time;
    cout << elapsed.count() << '\n';

    long long n = 1000000000000LL;
    cout << n << '\n';
    return 0;
}
