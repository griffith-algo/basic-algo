"""Prob1 example.

This file belongs to the week 11 dynamic programming and pattern-matching practice solutions. It uses badCharTable, find to illustrate the main idea with a small runnable example.
"""

# initialize pattern string
def badCharTable(pattern_string):
    """Build the bad-character shift table used by the Boyer-Moore-style search.

    Args:
        pattern_string (str): The pattern_string input used by this function.

    Returns:
        dict: The dictionary produced by the algorithm.
    """
    n = len(pattern_string)
    bad_char_table = {}

    for index,charater in enumerate(pattern_string):
        if index != n - 1:    
            bad_char_table[charater] = n - index - 1

    bad_char_table['other_character'] = n
    return bad_char_table

# find the character
def find(text,pattern_string):
    """Search the text for every occurrence of the pattern.

    Args:
        text (str): The text input used by this function.
        pattern_string (str): The pattern_string input used by this function.

    Returns:
        int: The integer result produced by the algorithm.
    """
    bad_char_table = badCharTable(pattern_string)
    m = len(text)
    n = len(pattern_string)
    i = 0 
    res = []

    while i < m - n + 1:
        for index,character in enumerate(reversed(pattern_string)):
            if character != text[i + n - index - 1]:
                if text[i + n - index - 1] in bad_char_table:
                    i += bad_char_table[text[i + n - index -1]]
                else:
                    i += bad_char_table['other_character']
                break

            if index == n - 1:
                res.append(i)
                i += bad_char_table[text[i + n - index -1]]
    # return the index that the pattern appeared in the text
    return res

if __name__ == '__main__':
    print(find('BESS_KNEW_ABOUT_BAOBABS',"BAOBAB"))