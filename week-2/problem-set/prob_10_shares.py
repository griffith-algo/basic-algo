def total_shares(n):
    total = 0
    i = 1
    while i <= n:
        shares = n // i
        last_day = n // shares
        days_in_group = last_day - i + 1
        total += shares * days_in_group
        i = last_day + 1
    return total

print(total_shares(10))