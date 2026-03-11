"""Prob1 example.

This file belongs to the worked week 1 problem-set solutions. It uses euclid_algorithm, euclid to illustrate the main idea with a small runnable example.
"""

def euclid_algorithm(m, n):
    """Compute the greatest common divisor iteratively and count the loop iterations.

    Args:
        m (int): The m input used by this function.
        n (int): The n input used by this function.

    Returns:
        tuple: The tuple of values produced by the algorithm.
    """
    count_exec = 0
    if m>=n:
        while n != 0:
            r = m % n
            m = n
            n = r
            count_exec += 1
            print(m,n)
        return m, count_exec
    else:
        while m != 0:
            r = n % m
            n = m
            m = r
            count_exec += 1
            print(m,n)
        return n, count_exec

def euclid (m,n, count):
    """Compute the greatest common divisor recursively and count the recursive steps.

    Args:
        m (int): The m input used by this function.
        n (int): The n input used by this function.
        count (int): The count input used by this function.

    Returns:
        tuple: The tuple of values produced by the algorithm.
    """
    if m < n: 
        count += 1
        print(m,n)
    if n == 0:
        return m, count
    gcd, subcount = euclid(n, m%n, count)
    count = subcount
    return gcd, count
    
    

# gcd, count = euclid_algorithm(24, 60)
gcd, count = euclid(24, 60, 0)
print("GCD: ", gcd)
print("Number of times: ", count)