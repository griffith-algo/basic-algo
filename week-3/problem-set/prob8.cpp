/**
 * @file prob8.cpp
 * @brief C++ version of the job-scheduling example.
 */

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

/**
 * @brief Order jobs to minimise the total completion time.
 * @param jobs vector<pair<int, int>> Jobs stored as (job_id, running_time).
 * @return int Sum of completion times after scheduling the jobs by shortest running time first.
 */
int schedule_jobs(vector<pair<int, int>> jobs) {
    sort(jobs.begin(), jobs.end(), [](const auto& left, const auto& right) {
        return left.second < right.second;
    });

    int total_time = 0;
    int start_time = 0;
    for (const auto& job : jobs) {
        total_time += start_time + job.second;
        start_time += job.second;
    }
    return total_time;
}

/**
 * @brief Run the job-scheduling demonstration.
 * @return int Exit status code returned to the operating system.
 */
int main() {
    vector<pair<int, int>> jobs = {{1, 5}, {2, 3}, {3, 7}, {4, 2}};
    cout << schedule_jobs(jobs) << '\n';
    return 0;
}
