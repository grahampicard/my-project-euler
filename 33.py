from typing import Tuple

def strip_vals(val, pattern):
    new_val = str(val).replace(pattern, "")
    if new_val == "":
        return
    else:
        return int(new_val)


def compare(num: int, den: int) ->  Tuple:

    # exclude trivial examples
    if num % 10 == 0:
        return

    # exclude cases where fraction is not in the interval (0, 1)
    elif num / den >= 1:
        return

    # find the intersection
    combined = set(str(num)).intersection(set(str(den)))    
    if len(combined) < 1:
        return

    # go through each intersecting variable
    pairs = []
    for digit in combined:
        stripped_num = strip_vals(num, digit)
        stripped_den = strip_vals(den, digit)

        if (not stripped_num) | (not stripped_den):
            return None

        if num / den == stripped_num / stripped_den:
            pairs.append((num, den))
     
    return pairs


fractions = 1

for x in range(11, 100):
    for y in range(11, 100):
        if x < y:
            res = compare(x,y)
            if res:
                for n, d in res:
                    fractions *= n / d

print(1 / fractions)
