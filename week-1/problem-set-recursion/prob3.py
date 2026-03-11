"""Prob3 example.

This file belongs to the week 1 recursion practice solutions. It demonstrates
how recursion can reverse a string either by building a new string or by
swapping a mutable list in place.
"""


def reverse_string(s):
    """Return a reversed copy of the given string using recursion.

    Args:
        s (str): The s input used by this function.

    Returns:
        str: The string produced by the algorithm.
    """
    if len(s) <= 1:
        return s
    return reverse_string(s[1:]) + s[0]


def reverse_inplace(s, left=0, right=None):
    """Reverse a mutable sequence in place using recursion.

    Args:
        s (str): The s input used by this function.
        left (object): The left boundary or left-side data used by the algorithm.
        right (object): The right boundary or right-side data used by the algorithm.

    Returns:
        object: The value produced by this function.
    """
    if right is None:
        right = len(s) - 1

    if left >= right:
        return s

    s[left], s[right] = s[right], s[left]
    return reverse_inplace(s, left + 1, right - 1)


def main():
    """Run the small demonstration for this teaching example.

    Returns:
        None: This function updates data or prints results and does not return a value.
    """
    text = "hello world"
    characters = list(text)

    print("Reversed copy:", reverse_string(text))
    reverse_inplace(characters)
    print("Reversed in place:", "".join(characters))


if __name__ == "__main__":
    main()
