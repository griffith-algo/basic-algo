"""Prob9 example.

This file belongs to the week 2 data-structure and graph practice solutions. It
shows two ways to sort a queue while only using queue-like helper structures.
"""


def order_queue_two(original_queue):
    """Sort a queue using two helper queues.

    Args:
        original_queue (list): The original_queue input used by this function.

    Returns:
        None: This function updates data or prints results and does not return a value.
    """
    working_queue = list(original_queue)
    buffer_queue = []
    sorted_queue = []

    while working_queue:
        current_min = working_queue.pop(0)

        while working_queue:
            value = working_queue.pop(0)
            if value < current_min:
                buffer_queue.append(current_min)
                current_min = value
            else:
                buffer_queue.append(value)

        sorted_queue.append(current_min)
        working_queue = buffer_queue
        buffer_queue = []

    original_queue.clear()
    original_queue.extend(sorted_queue)


def order_queue_one(original_queue):
    """Sort a queue using one helper queue.

    Args:
        original_queue (list): The original_queue input used by this function.

    Returns:
        None: This function updates data or prints results and does not return a value.
    """
    working_queue = list(original_queue)
    helper_queue = []

    while working_queue:
        current_value = working_queue.pop(0)

        while helper_queue and helper_queue[-1] > current_value:
            working_queue.append(helper_queue.pop())

        helper_queue.append(current_value)

    original_queue.clear()
    original_queue.extend(helper_queue)


def main():
    """Run the small demonstration for this teaching example.

    Returns:
        None: This function updates data or prints results and does not return a value.
    """
    first_queue = [4, 1, 3, 2, 5]
    order_queue_two(first_queue)
    print(first_queue)

    second_queue = [4, 1, 3, 2, 5]
    order_queue_one(second_queue)
    print(second_queue)


if __name__ == "__main__":
    main()
