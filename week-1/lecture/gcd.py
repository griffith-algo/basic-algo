"""Gcd example.

This file belongs to the introductory lecture examples on recursion, searching,
and simple sorting. It uses Euclid's algorithm to compute the greatest common
divisor of two integers.
"""


def gcd(m, n):
    """Compute the greatest common divisor using recursive Euclid's algorithm.

    Args:
        m (int): The m input used by this function.
        n (int): The n input used by this function.

    Returns:
        int: The integer result produced by the algorithm.
    """
    m = abs(m)
    n = abs(n)

    # Euclid's algorithm still works if we swap the values so the larger one
    # comes first.
    if m < n:
        m, n = n, m

    if n == 0:
        return m

    return gcd(n, m % n)


def main():
    """Run the small demonstration for this teaching example.

    Returns:
        None: This function updates data or prints results and does not return a value.
    """
    m = 60
    n = 24
    print(f"gcd({m}, {n}) = {gcd(m, n)}")


if __name__ == "__main__":
    main()
