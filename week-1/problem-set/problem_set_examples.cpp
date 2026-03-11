#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <numeric>
#include <string>
#include <utility>
#include <vector>

using namespace std;

/**
 * @brief Compute the greatest common divisor iteratively and count the loop steps.
 * @param m int The size value used by the function.
 * @param n int The size value or number of recursive steps used by the function.
 * @return pair<int, int> The pair of values produced by the algorithm.
 */
pair<int, int> euclid_algorithm(int m, int n) {
    int count = 0;
    m = abs(m);
    n = abs(n);
    while (n != 0) {
        int remainder = m % n;
        m = n;
        n = remainder;
        ++count;
    }
    return {m, count};
}

/**
 * @brief Compute the greatest common divisor recursively and count the recursive steps.
 * @param m int The size value used by the function.
 * @param n int The size value or number of recursive steps used by the function.
 * @param count int The count value used by this function.
 * @return pair<int, int> The pair of values produced by the algorithm.
 */
pair<int, int> euclid_recursive_impl(int m, int n, int count) {
    m = abs(m);
    n = abs(n);
    if (m < n) {
        swap(m, n);
    }
    if (n == 0) {
        return {m, count};
    }
    return euclid_recursive_impl(n, m % n, count + 1);
}

/**
 * @brief Compute the greatest common divisor recursively and return the result and step count.
 * @param m int The size value used by the function.
 * @param n int The size value or number of recursive steps used by the function.
 * @return pair<int, int> The pair of values produced by the algorithm.
 */
pair<int, int> euclid(int m, int n) {
    return euclid_recursive_impl(m, n, 0);
}

/**
 * @brief Simulate the locker toggling process exactly as written in the puzzle.
 * @param n int The size value or number of recursive steps used by the function.
 * @return vector<bool> The vector produced by the algorithm.
 */
vector<bool> toggle_lockers_from_scratch(int n) {
    vector<bool> lockers(n, false);
    for (int student = 1; student <= n; ++student) {
        for (int locker = student; locker <= n; locker += student) {
            lockers[locker - 1] = !lockers[locker - 1];
        }
    }
    return lockers;
}

/**
 * @brief Use the perfect-square shortcut to find which lockers stay open.
 * @param n int The size value or number of recursive steps used by the function.
 * @return vector<bool> The vector produced by the algorithm.
 */
vector<bool> toggle_lockers(int n) {
    vector<bool> lockers(n, false);
    for (int value = 1; value * value <= n; ++value) {
        lockers[value * value - 1] = true;
    }
    return lockers;
}

/**
 * @brief Build a readable label for one person in the bridge puzzle.
 * @param times const vector<int>& The times value used by this function.
 * @param time_value int The time_value value used by this function.
 * @return string The string produced by the algorithm.
 */
string person_label(const vector<int>& times, int time_value) {
    auto index = static_cast<int>(find(times.begin(), times.end(), time_value) - times.begin()) + 1;
    return "Person " + to_string(index) + " (" + to_string(time_value) + " min)";
}

struct BridgeState {
    vector<int> arrived;
    vector<int> remaining;
    int travel_time;
    vector<string> steps;
};

/**
 * @brief Simulate one crossing and one return in the bridge-and-torch puzzle.
 * @param combination pair<int, int> The combination value used by this function.
 * @param arrived const vector<int>& The arrived value used by this function.
 * @param steps const vector<string>& The steps value used by this function.
 * @param times const vector<int>& The times value used by this function.
 * @return BridgeState The value produced by this function.
 */
BridgeState cross_bridge(pair<int, int> combination, const vector<int>& arrived,
                         const vector<string>& steps, const vector<int>& times) {
    vector<int> updated_arrived = arrived;
    updated_arrived.push_back(combination.first);
    updated_arrived.push_back(combination.second);

    int flash_return = *min_element(updated_arrived.begin(), updated_arrived.end());
    updated_arrived.erase(find(updated_arrived.begin(), updated_arrived.end(), flash_return));

    vector<int> remaining;
    for (int time_value : times) {
        if (find(updated_arrived.begin(), updated_arrived.end(), time_value) == updated_arrived.end()) {
            remaining.push_back(time_value);
        }
    }

    int crossing_time = max(combination.first, combination.second);
    vector<string> updated_steps = steps;
    updated_steps.push_back(
        person_label(times, combination.first) + " and " + person_label(times, combination.second) +
        " cross (" + to_string(crossing_time) + " min). " +
        person_label(times, flash_return) + " returns (" + to_string(flash_return) + " min)."
    );

    return {updated_arrived, remaining, crossing_time + flash_return, updated_steps};
}

/**
 * @brief Search for bridge-puzzle solutions that meet the time limit.
 * @param times const vector<int>& The times value used by this function.
 * @param time_limit int The time_limit value used by this function.
 * @return vector<pair<int, vector<string>>> The vector produced by the algorithm.
 */
vector<pair<int, vector<string>>> solve_bridge_puzzle(const vector<int>& times, int time_limit) {
    vector<pair<int, vector<string>>> solutions;

    for (size_t i = 0; i < times.size(); ++i) {
        for (size_t j = i + 1; j < times.size(); ++j) {
            BridgeState first = cross_bridge({times[i], times[j]}, {}, {}, times);
            for (size_t a = 0; a < first.remaining.size(); ++a) {
                for (size_t b = a + 1; b < first.remaining.size(); ++b) {
                    BridgeState second = cross_bridge(
                        {first.remaining[a], first.remaining[b]}, first.arrived, first.steps, times
                    );
                    int final_crossing = max(second.remaining[0], second.remaining[1]);
                    int total_time = first.travel_time + second.travel_time + final_crossing;
                    if (total_time <= time_limit) {
                        vector<string> steps = second.steps;
                        steps.push_back(
                            person_label(times, second.remaining[0]) + " and " +
                            person_label(times, second.remaining[1]) + " cross (" +
                            to_string(final_crossing) + " min)."
                        );
                        solutions.push_back({total_time, steps});
                    }
                }
            }
        }
    }

    sort(solutions.begin(), solutions.end(), [](const auto& left, const auto& right) {
        return left.first < right.first;
    });
    return solutions;
}

/**
 * @brief Convert a decimal number to its binary representation.
 * @param value int The value value used by this function.
 * @return string The string produced by the algorithm.
 */
string decimal_to_binary(int value) {
    if (value == 0) {
        return "0";
    }

    string bits;
    while (value > 0) {
        bits.push_back(static_cast<char>('0' + (value % 2)));
        value /= 2;
    }
    reverse(bits.begin(), bits.end());
    return bits;
}

/**
 * @brief Return the smallest difference between any two values in the list.
 * @param values vector<int> The vector of values processed by the function.
 * @return int The integer result produced by the algorithm.
 */
int min_distance(vector<int> values) {
    sort(values.begin(), values.end());
    int best = numeric_limits<int>::max();
    for (size_t i = 1; i < values.size(); ++i) {
        best = min(best, values[i] - values[i - 1]);
    }
    return best;
}

/**
 * @brief Sort the list using comparison counting sort.
 * @param values const vector<int>& The vector of values processed by the function.
 * @return vector<int> The vector produced by the algorithm.
 */
vector<int> comparison_counting_sort(const vector<int>& values) {
    int n = static_cast<int>(values.size());
    vector<int> count(n, 0);
    vector<int> sorted(n, 0);

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (values[i] < values[j]) {
                ++count[j];
            } else {
                ++count[i];
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        sorted[count[i]] = values[i];
    }
    return sorted;
}

/**
 * @brief Check whether all points lie on the same circle.
 * @param points const vector<pair<double, double>>& The points used by the geometry algorithm.
 * @return bool True when the required condition is satisfied, otherwise false.
 */
bool on_same_circumference(const vector<pair<double, double>>& points) {
    if (points.size() < 3) {
        return true;
    }

    double x1 = points[0].first;
    double y1 = points[0].second;
    double x2 = points[1].first;
    double y2 = points[1].second;
    double x3 = points[2].first;
    double y3 = points[2].second;

    double denominator = 2.0 * (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
    if (abs(denominator) < 1e-9) {
        return false;
    }

    double a = ((x1 * x1 + y1 * y1) * (y2 - y3) +
                (x2 * x2 + y2 * y2) * (y3 - y1) +
                (x3 * x3 + y3 * y3) * (y1 - y2)) / denominator;
    double b = ((x1 * x1 + y1 * y1) * (x3 - x2) +
                (x2 * x2 + y2 * y2) * (x1 - x3) +
                (x3 * x3 + y3 * y3) * (x2 - x1)) / denominator;

    double radius = hypot(x1 - a, y1 - b);
    for (const auto& point : points) {
        if (abs(hypot(point.first - a, point.second - b) - radius) > 1e-9) {
            return false;
        }
    }
    return true;
}

/**
 * @brief Delete one element by swapping it with the last value.
 * @param values vector<int>& The vector of values processed by the function.
 * @param index size_t The index value used by this function.
 * @return void This function updates data or prints results and does not return a value.
 */
void delete_element(vector<int>& values, size_t index) {
    swap(values[index], values.back());
    values.pop_back();
}

class SortedArray {
public:
    /**
     * @brief Run the SortedArray step used in this example.
     * @param values vector<int> The vector of values processed by the function.
     * @return explicit The value produced by this function.
     */
    explicit SortedArray(vector<int> values) : values_(move(values)), deleted_(values_.size(), false) {}

    /**
     * @brief Run the delete index step used in this example.
     * @param index size_t The index value used by this function.
     * @return void This function updates data or prints results and does not return a value.
     */
    void delete_index(size_t index) {
        deleted_[index] = true;
    }

    /**
     * @brief Run the search step used in this example.
     * @param target int The target peg, basket, or value used in the example.
     * @return int The integer result produced by the algorithm.
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
     * @brief Run the active values step used in this example.
     * @return vector<int> The vector produced by the algorithm.
     */
    vector<int> active_values() const {
        vector<int> result;
        for (size_t i = 0; i < values_.size(); ++i) {
            if (!deleted_[i]) {
                result.push_back(values_[i]);
            }
        }
        return result;
    }

private:
    /**
     * @brief Run the nearest active index step used in this example.
     * @param mid int The middle index used to split the current range.
     * @param left int The left-side data or left boundary used by the algorithm.
     * @param right int The right-side data or right boundary used by the algorithm.
     * @return int The integer result produced by the algorithm.
     */
    int nearest_active_index(int mid, int left, int right) const {
        for (int offset = 0; mid - offset >= left || mid + offset <= right; ++offset) {
            int left_candidate = mid - offset;
            int right_candidate = mid + offset;
            if (left_candidate >= left && !deleted_[left_candidate]) {
                return left_candidate;
            }
            if (right_candidate <= right && !deleted_[right_candidate]) {
                return right_candidate;
            }
        }
        return -1;
    }

    vector<int> values_;
    vector<bool> deleted_;
};

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
    auto iterative = euclid_algorithm(24, 60);
    auto recursive = euclid(24, 60);
    cout << "Iterative Euclid: gcd = " << iterative.first << ", steps = " << iterative.second << '\n';
    cout << "Recursive Euclid: gcd = " << recursive.first << ", steps = " << recursive.second << "\n\n";

    auto lockers = toggle_lockers(20);
    cout << "Open lockers using the square-number shortcut: ";
    for (size_t i = 0; i < lockers.size(); ++i) {
        if (lockers[i]) {
            cout << (i + 1) << ' ';
        }
    }
    cout << "\n\n";

    vector<int> times = {1, 2, 5, 10};
    auto bridge_solutions = solve_bridge_puzzle(times, 17);
    if (!bridge_solutions.empty()) {
        cout << "Bridge puzzle solution with total time " << bridge_solutions.front().first << ":\n";
        for (const string& step : bridge_solutions.front().second) {
            cout << "  " << step << '\n';
        }
    }
    cout << '\n';

    cout << "128 in binary is " << decimal_to_binary(128) << "\n";
    cout << "Minimum distance in [2, 4, 8, 3, 10] is " << min_distance({2, 4, 8, 3, 10}) << "\n";

    cout << "Comparison counting sort: ";
    print_vector(comparison_counting_sort({60, 35, 81, 98, 14, 47}));
    cout << '\n';

    vector<pair<double, double>> points = {{1, -1}, {-1, 1}, {1, 1}, {-1, -1}};
    cout << "Points on the same circumference: " << boolalpha << on_same_circumference(points) << "\n";

    vector<int> values = {1, 2, 3, 4, 5};
    delete_element(values, 2);
    cout << "Delete by swapping with the end: ";
    print_vector(values);
    cout << '\n';

    SortedArray sorted_array({1, 2, 3, 4, 5});
    sorted_array.delete_index(2);
    cout << "Lazy deletion active values: ";
    print_vector(sorted_array.active_values());
    cout << '\n';
    cout << "Index of 4 after lazy deletion: " << sorted_array.search(4) << '\n';
    return 0;
}
