from typing import BinaryIO


def palindrome(val) -> bool:
    if type(val) != str:
        val = str(val)
    fwd_cnt = 0
    bck_cnt = len(val) - 1
    while fwd_cnt < bck_cnt:
        if val[fwd_cnt] != val[bck_cnt]:
            return False
        fwd_cnt += 1
        bck_cnt -= 1
    return True

def to_bin(base10) -> str:
    return bin(base10)[2:]


total = 0
for x in range(1000000):
    if palindrome(x):
        if palindrome(to_bin(x)):
            total += x

print(total)
