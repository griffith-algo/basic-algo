"""Prob6 example.

This file belongs to the week 1 recursion practice solutions. It checks whether
strings are palindromes by comparing the first and last characters recursively.
"""


def clean_text(text):
    """Remove punctuation and spaces so the palindrome test is easier to read.

    Args:
        text (str): The text input used by this function.

    Returns:
        str: The string produced by the algorithm.
    """
    return "".join(character.lower() for character in text if character.isalnum())


def is_palindrome(s, length):
    """Return True when the given text reads the same forwards and backwards.

    Args:
        s (str): The s input used by this function.
        length (int): The length input used by this function.

    Returns:
        bool: True when the required condition is satisfied, otherwise False.
    """
    if length <= 1:
        return True

    if s[0] != s[length - 1]:
        return False

    return is_palindrome(s[1 : length - 1], length - 2)


def main():
    """Run the small demonstration for this teaching example.

    Returns:
        None: This function updates data or prints results and does not return a value.
    """
    examples = [
        "racecar",
        "hello",
        "A man, a plan, a canal, Panama!",
    ]

    for text in examples:
        cleaned = clean_text(text)
        print(f"{text!r} -> {is_palindrome(cleaned, len(cleaned))}")


if __name__ == "__main__":
    main()
