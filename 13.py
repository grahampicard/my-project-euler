import math

INPUT_FILE = "./inputs/13.txt"

with open(INPUT_FILE, "r") as f:
    input_nums = f.readlines()

total = 0

for i, num in enumerate(input_nums):
    num_str = num.replace("\n", "")
    number = int(num_str.strip())
    total += number

while total > 10 ** 10:
    total /= 10

print(math.floor(total))
