"""Prob2 example.

This file belongs to the week 11 dynamic programming and pattern-matching
practice solutions. It computes the longest common subsequence of two strings.
"""


def lcs(x, y):
    """Return both the length and one example of the longest common subsequence.

    Args:
        x (int): The x input used by this function.
        y (int): The y input used by this function.

    Returns:
        tuple: The tuple of values produced by the algorithm.
    """
    m = len(x)
    n = len(y)
    table = [[0] * (n + 1) for _ in range(m + 1)]

    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if x[i - 1] == y[j - 1]:
                table[i][j] = table[i - 1][j - 1] + 1
            else:
                table[i][j] = max(table[i - 1][j], table[i][j - 1])

    # Walk backwards through the table to rebuild one valid subsequence.
    i = m
    j = n
    characters = []

    while i > 0 and j > 0:
        if x[i - 1] == y[j - 1]:
            characters.append(x[i - 1])
            i -= 1
            j -= 1
        elif table[i - 1][j] >= table[i][j - 1]:
            i -= 1
        else:
            j -= 1

    return table[m][n], "".join(reversed(characters))


def main():
    """Run the small demonstration for this teaching example.

    Returns:
        None: This function updates data or prints results and does not return a value.
    """
    result = lcs("intention", "execution")
    print("LCS:", result)


if __name__ == "__main__":
    main()
