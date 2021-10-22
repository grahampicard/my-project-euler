"""
145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.

Find the sum of all numbers which are equal to the sum of the factorial of their digits.

Note: As 1! = 1 and 2! = 2 are not sums they are not included.
"""

def factorial(num):
    prod = 1
    for i in range(num):
        prod *= (i + 1)
    return prod


def check_factorial_num(number: int) -> bool:
    digits = list(str(number))
    if len(digits) == 1: return False
    digit_sum = 0
    for d in digits:
        digit_sum += factorial(int(d))
        if digit_sum > number:
            return False

    result = digit_sum == number
    return result

results = []
for x in range(100000):
    if check_factorial_num(x):
        results.append(x)

print(sum(results))

