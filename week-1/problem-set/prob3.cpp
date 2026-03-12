/**
 * @file prob3.cpp
 * @brief C++ version of the bridge-and-torch puzzle search.
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

struct BridgeState {
    vector<int> arrived;
    vector<int> remaining;
    int travel_time;
    vector<string> steps;
};

/**
 * @brief Return a readable label for the person with the given crossing time.
 * @param times const vector<int>& Ordered list of crossing times. Each value has type int.
 * @param time_value int Crossing time of the person being labelled.
 * @return string Human-readable description such as "Person 1 (1 min)".
 */
string person_label(const vector<int>& times, int time_value) {
    int person_number = static_cast<int>(find(times.begin(), times.end(), time_value) - times.begin()) + 1;
    return "Person " + to_string(person_number) + " (" + to_string(time_value) + " min)";
}

/**
 * @brief Simulate one crossing and the fastest possible torch return.
 * @param combination pair<int, int> Two crossing times chosen for the current move.
 * @param arrived const vector<int>& People already on the far side after earlier moves.
 * @param solution const vector<string>& Solution steps collected so far.
 * @param times const vector<int>& Ordered list of all crossing times.
 * @return BridgeState Updated state after the crossing and the return trip.
 */
BridgeState cross_bridge(pair<int, int> combination,
                         const vector<int>& arrived,
                         const vector<string>& solution,
                         const vector<int>& times) {
    int crossing_time = max(combination.first, combination.second);
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

    string step_text = person_label(times, combination.first) + " and " +
                       person_label(times, combination.second) + " cross (" +
                       to_string(crossing_time) + " min). " +
                       person_label(times, flash_return) + " returns (" +
                       to_string(flash_return) + " min).";

    vector<string> updated_solution = solution;
    updated_solution.push_back(step_text);

    return {updated_arrived, remaining, crossing_time + flash_return, updated_solution};
}

/**
 * @brief Run the bridge-and-torch search and print every solution within the time limit.
 * @return int Exit status code returned to the operating system.
 */
int main() {
    vector<int> times = {1, 2, 5, 10};
    int time_limit = 17;
    vector<pair<int, vector<string>>> solutions;

    for (size_t i = 0; i < times.size(); ++i) {
        for (size_t j = i + 1; j < times.size(); ++j) {
            BridgeState first_state = cross_bridge({times[i], times[j]}, {}, {}, times);

            for (size_t a = 0; a < first_state.remaining.size(); ++a) {
                for (size_t b = a + 1; b < first_state.remaining.size(); ++b) {
                    BridgeState second_state = cross_bridge(
                        {first_state.remaining[a], first_state.remaining[b]},
                        first_state.arrived,
                        first_state.steps,
                        times
                    );

                    int final_crossing = max(second_state.remaining[0], second_state.remaining[1]);
                    int total_time = first_state.travel_time + second_state.travel_time + final_crossing;

                    if (total_time <= time_limit) {
                        vector<string> steps = second_state.steps;
                        steps.push_back(
                            person_label(times, second_state.remaining[0]) + " and " +
                            person_label(times, second_state.remaining[1]) + " cross (" +
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

    for (size_t index = 0; index < solutions.size(); ++index) {
        cout << "Solution " << (index + 1) << ":\n";
        for (const string& step : solutions[index].second) {
            cout << "  " << step << '\n';
        }
        cout << "  Total time: " << solutions[index].first << " minutes\n\n";
    }

    return 0;
}
