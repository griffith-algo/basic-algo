"""List Primes example.

This file belongs to the introductory lecture examples on recursion, searching, and simple sorting. It uses get_primes, sieve_of_eratosthenes to illustrate the main idea with a small runnable example.
"""

def get_primes(n):
    """Return every prime number from 2 up to the given limit using trial division.

    Args:
        n (int): The n input used by this function.

    Returns:
        list: The list produced by the algorithm.
    """
    primes = []
    for num in range(2, n+1):
        is_prime = True
        for factor in range(2, num):
            if num % factor == 0:
                is_prime = False
                break
        if is_prime:
            primes.append(num)
    return primes

def sieve_of_eratosthenes(n):
    # Create a boolean array "prime[0..n]" and initialize
    # all entries it as true. A value in prime[i] will
    # finally be false if it is Not a prime, else true.
    """Return every prime number from 2 up to the given limit using the sieve method.

    Args:
        n (int): The n input used by this function.

    Returns:
        list: The list produced by the algorithm.
    """
    prime = [True for i in range(n+1)]
    p = 2
    while (p * p <= n):
        # If prime[p] is not changed, then it is a prime
        if (prime[p] == True):
            # Update all multiples of p
            for i in range(p * 2, n+1, p):
                prime[i] = False
        p += 1
    # Return all prime numbers
    primes = []
    for p in range(2, n+1):
        if prime[p]:
            primes.append(p)
    return primes


import timeit

n = 10000

result = timeit.timeit(stmt='get_primes(n)', globals=globals(), number=1)
print(f"Execution time is {result} seconds")

result = timeit.timeit(stmt='sieve_of_eratosthenes(n)', globals=globals(), number=1)
print(f"Execution time is {result} seconds")

