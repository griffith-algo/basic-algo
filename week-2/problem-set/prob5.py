"""Prob5 example.

This file belongs to the week 2 data-structure and graph practice solutions. It uses is_anagram to illustrate the main idea with a small runnable example.
"""

def is_anagram(word1, word2):
    # Convert both words to lowercase and remove non-letter characters
    """Return True when the two words contain the same letters.

    Args:
        word1 (str): The word1 input used by this function.
        word2 (str): The word2 input used by this function.

    Returns:
        bool: True when the required condition is satisfied, otherwise False.
    """
    word1 = ''.join(c for c in word1.lower() if c.isalpha())
    word2 = ''.join(c for c in word2.lower() if c.isalpha())
    
    # Sort the letters of each word in alphabetical order
    sorted_word1 = sorted(word1)
    sorted_word2 = sorted(word2)
    
    # Compare the sorted letter sequences of the two words
    return sorted_word1 == sorted_word2

print(is_anagram("tea", "eat"))  # True
print(is_anagram("silent", "listen"))  # True
print(is_anagram("desserts", "stressed"))  # True
print(is_anagram("hello", "world"))  # False
