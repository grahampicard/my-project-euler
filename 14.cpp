// The following iterative sequence is defined for the set of positive
// int64_tegers: n → n/2 (n is even) n → 3n + 1 (n is odd) Using the rule above
// and starting with 13, we generate the following sequence: 13 → 40 → 20 → 10 →
// 5 → 16 → 8 → 4 → 2 → 1 It can be seen that this sequence (starting at 13 and
// finishing at 1) contains 10 terms. Although it has not been proved yet
// (Collatz Problem), it is thought that all starting numbers finish at 1. Which
// starting number, under one million, produces the longest chain? NOTE: Once
// the chain starts the terms are allowed to go above one million.
#include <iostream>

int64_t collatz(int64_t num) {
  if (num % 2 == 0) {
    return num / 2;
  } else {
    return num * 3 + 1;
  }
}

int64_t collatzChain(int64_t start) {
  int64_t count = 1;
  while (start > 1) {
    ++count;
    start = collatz(start);
  }
  return count;
}

int main() {
  int64_t maxChain = 1;
  int64_t val = 1;
  for (int64_t i = 2; i < 1000000; ++i) {
    if (collatzChain(i) > maxChain) {
      maxChain = collatzChain(i);
      val = i;
    }
  }
  std::cout << val << std::endl;
  return 0;
}
