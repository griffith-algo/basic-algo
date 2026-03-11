"""Prob4 example.

This file belongs to the week 4 divide-and-conquer and memoization examples. It
computes powers of two with a simple recursive definition.
"""


def power_of_two(n):
    """Return 2 raised to the power n using recursion.

    Args:
        n (int): The n input used by this function.

    Returns:
        int: The integer result produced by the algorithm.
    """
    if n == 0:
        return 1
    return 2 * power_of_two(n - 1)


def main():
    """Run the small demonstration for this teaching example.

    Returns:
        None: This function updates data or prints results and does not return a value.
    """
    print(power_of_two(5))


if __name__ == "__main__":
    main()
