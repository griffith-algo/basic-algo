"""Prob3 example.

This file belongs to the worked week 1 problem-set solutions. It explores the
classic bridge-and-torch puzzle with a brute-force search over the first two
crossings.
"""

import itertools

times = [1, 2, 5, 10]


def person_label(time_value):
    """Return a readable label for the person with the given crossing time.

    Args:
        time_value (object): The time_value input used by this function.

    Returns:
        str: The string produced by the algorithm.
    """
    person_number = times.index(time_value) + 1
    return f"Person {person_number} ({time_value} min)"


def cross_bridge(combination, arrived, solution):
    """Simulate one crossing and the fastest possible return with the torch.

    Args:
        combination (tuple): The combination input used by this function.
        arrived (list): The arrived input used by this function.
        solution (object): The solution steps built so far.

    Returns:
        tuple: The tuple of values produced by the algorithm.
    """
    crossing_time = max(combination)

    # The chosen pair crosses to the far side.
    updated_arrived = arrived.copy()
    updated_arrived.extend(combination)

    # The fastest person on the far side brings the torch back.
    flash_return = min(updated_arrived)
    updated_arrived.remove(flash_return)

    remaining = [time for time in times if time not in updated_arrived]
    step_text = (
        f"{person_label(combination[0])} and {person_label(combination[1])} cross "
        f"({crossing_time} min). {person_label(flash_return)} returns "
        f"({flash_return} min)."
    )

    updated_solution = solution + [step_text]
    return updated_arrived, remaining, crossing_time + flash_return, updated_solution


def main():
    """Run the small demonstration for this teaching example.

    Returns:
        None: This function updates data or prints results and does not return a value.
    """
    time_limit = 17
    solutions = []

    for first_pair in itertools.combinations(times, 2):
        arrived_after_first, remaining_after_first, first_cost, first_steps = cross_bridge(
            first_pair, [], []
        )

        for second_pair in itertools.combinations(remaining_after_first, 2):
            arrived_after_second, remaining, second_cost, second_steps = cross_bridge(
                second_pair, arrived_after_first, first_steps
            )

            final_crossing = max(remaining)
            total_time = first_cost + second_cost + final_crossing

            if total_time <= time_limit:
                final_step = (
                    f"{person_label(remaining[0])} and {person_label(remaining[1])} cross "
                    f"({final_crossing} min)."
                )
                solutions.append((total_time, second_steps + [final_step]))

    for solution_number, (total_time, steps) in enumerate(sorted(solutions), start=1):
        print(f"Solution {solution_number}:")
        for step in steps:
            print(f"  {step}")
        print(f"  Total time: {total_time} minutes\n")


if __name__ == "__main__":
    main()
