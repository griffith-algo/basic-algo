"""Prob7 example.

This file belongs to the week 1 recursion practice solutions. It uses replace to illustrate the main idea with a small runnable example.
"""

def replace(s, from_char, to_char):
    """This function recursively replaces all occurrences of a character in a string with another character.

    Args:
        s (str): The s input used by this function.
        from_char (str): The from_char input used by this function.
        to_char (str): The to_char input used by this function.

    Returns:
        str: The string produced by the algorithm.
    """
    if not s:
        # Base case: the string is empty
        return s
    
    if s[0] == from_char:
        # Recursive case: replace the first character if it matches the from_char
        return to_char + replace(s[1:], from_char, to_char)
    else:
        # Recursive case: keep the first character and continue with the rest of the string
        return s[0] + replace(s[1:], from_char, to_char)

s = "steve"
from_char = 'e'
to_char = 'a'

s = replace(s, from_char, to_char)

print(s)  # Output: "stava"
