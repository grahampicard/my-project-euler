"""
How many such routes are there through a 20×20 grid?

Essentilaly, this represents a modification of bernoulli's triangle,
plus one, for a given row, for a diamond pattern.
"""

def paths(rows) -> int:
    if rows < 1:
        return

    current_row = 1

    mtx = [[0 for x in range(rows * 2)] for y in range(rows * 2)]
    mtx[0][0] = 1

    # Start the diamond, iterate incrementally
    while current_row < rows:
        for i, _ in enumerate(mtx[current_row]):
            for const in (-1, 0):
                try:
                    mtx[current_row][i] += mtx[current_row - 1][i + const]
                except:
                    pass
        current_row += 1

    # Work back to 0
    skip = 0
    while skip < rows:
        for i, _ in enumerate(mtx[current_row]):
            if (i > skip) & (i < rows):
                for const in (-1, 0):
                    try:
                        mtx[current_row][i] += mtx[current_row - 1][i + const]
                    except:
                        pass
        skip += 1
        current_row += 1

    return sum([sum(x) for x in mtx]) + 1

if __name__ == "__main__":
    print(paths(20))
