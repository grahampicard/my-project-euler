"""
Let d(n) be defined as the sum of proper divisors of n (numbers less than n 
which divide evenly into n). If d(a) = b and d(b) = a, where a ≠ b, then a 
and b are an amicable pair and each of a and b are called amicable numbers.

For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44,
55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4,
71 and 142; so d(284) = 220.

Evaluate the sum of all the amicable numbers under 10000.
"""


def amicable(n):
    i = 1
    divisors = set()
    while i <= n / 2:
        if n % i == 0:
            if i in divisors:
                break
            else:
                divisors.add(i)
                if i > 1:
                    divisors.add(int(n / i))
        i += 1

    return sum(divisors)


amicable_nums = set()
for i in range(1, 10000):
    a, b = i, amicable(i)
    db = amicable(b)

    if (a == db) & (a != b):
        amicable_nums.add(a)
        amicable_nums.add(b)

print(sum(amicable_nums))
