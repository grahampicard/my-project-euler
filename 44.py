import itertools

def pentagonal(n):
    return int(n * (3 * n - 1) / 2)

pos_counter = 1
pentags = [pentagonal(1)]
matches = []
while True:
    pos_counter += 1
    new_p = pentagonal(pos_counter)
    for p in pentags:
        if ((new_p + p) in pentags) & ((new_p - p) in pentags):
            matches.append((p, new_p))
            print(p, new_p)
    pentags.append(new_p)
    if pos_counter % 1000 == 0:
        breakpoint()
