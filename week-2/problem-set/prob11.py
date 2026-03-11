"""Prob11 example.

This file belongs to the week 2 data-structure and graph practice solutions. It uses stock_span to illustrate the main idea with a small runnable example.
"""

def stock_span(prices):
    """Compute the stock span for each day using a stack.

    Args:
        prices (list): The stock prices used by the span calculation.

    Returns:
        list: The list produced by the algorithm.
    """
    stk = []
    span = []

    for i in range(len(prices)):
        cur_span = 1
        while stk and prices[stk[-1]] <= prices[i]:
            prev_idx = stk.pop()
            cur_span += span[prev_idx]
        span.append(cur_span)
        stk.append(i)

    return span



import time

start_time = time.time()
# calculateShares(10**12)
# calculateShares(3)
prices = [100, 80, 60, 70, 60, 75, 85]
print(stock_span(prices))
end_time = time.time()
print(end_time - start_time)

n = 10**12
print(n)
