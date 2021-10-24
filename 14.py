def collatz(num: int) -> int:
    if num % 2 == 0:
        return num / 2
    return num * 3 + 1

def collatz_chain(num: int) -> int:
    count = 1
    while num > 1:
        num = collatz(num)
        count += 1
    return count


val = 1
chain_length = 1
for x in range(2,1000000):
    length = collatz_chain(x)
    if length > chain_length:
        chain_length = length
        val = x

print(val)
