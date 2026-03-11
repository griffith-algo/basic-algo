"""Prob8 example.

This file belongs to the week 3 problem-set solutions on sorting, greedy algorithms, and dynamic programming. It uses schedule_jobs to illustrate the main idea with a small runnable example.
"""

def schedule_jobs(jobs):
    """Order jobs to minimise the total completion time.

    Args:
        jobs (list): The jobs with their identifiers and running times.

    Returns:
        int: The integer result produced by the algorithm.
    """
    sorted_jobs = sorted(jobs, key=lambda x: x[1])
    total_time = 0
    start_time = 0
    for job in sorted_jobs:
        total_time += start_time + job[1]
        start_time += job[1]
    return total_time

jobs = [(1, 5), (2, 3), (3, 7), (4, 2)]
total_time = schedule_jobs(jobs)
print(total_time)  
# prints 34
# 2 + 2+3 + 2+3+5 + 2+3+5+7
