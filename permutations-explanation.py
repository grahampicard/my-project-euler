def permutations(iterable):
    hist = []
    hist2 = []

    # pool lists all the values we care about
    pool = tuple(iterable)

    # n is the # of values
    n = len(pool)

    # indices is a list of all the values. Probably for construction?
    indices = list(range(n))

    # cycles is a reverse list, I'm not sure how it's used.
    cycles = list(range(n, 0, -1))

    # add the first value
    hist.append(tuple(pool[i] for i in indices[:n]))
    hist2.append(list(indices))

    # yield tuple(pool[i] for i in indices[:n])
    # this should always run?
    while n:
        # this will create iterators per each n
        for i in reversed(range(n)):

            # So in this case, we take one from the END of the cycle
            cycles[i] -= 1

            # once we run out of values in that branch,
            if cycles[i] == 0:

                # we swap indices and keep going
                indices[i:] = indices[i+1:] + indices[i:i+1]

                # and remove value from cycle
                cycles[i] = n - i
            else:
                # we take a tree that starts at that value
                j = cycles[i]

                # we flip the i & j
                indices[i], indices[-j] = indices[-j], indices[i]

                # return
                # yield tuple(pool[i] for i in indices[:n])
                hist.append(tuple(pool[i] for i in indices[:n]))
                hist2.append(list(indices))
                break
        else:
            return hist, hist2

res = permutations("abcd")
for x in res[0]:
    print(x)

for y in res[1]:
    print(y)
