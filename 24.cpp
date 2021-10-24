#include <math.h>

#include <iostream>
#include <vector>

int factorial(int nDigits) {
  int prod = 1;
  while (nDigits > 1) {
    prod *= nDigits;
    --nDigits;
  }
  return prod;
}

int digitIndex(int idx, std::vector<int> digits) {
  float digitSize = digits.size();
  float permutations = factorial(digitSize);
  return std::floor(idx / permutations * digitSize);
}

int main() {
  std::vector<int> digits = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::vector<int> value;
  int idx = 999999;

  while (digits.size() > 0) {
    float digitSize = digits.size();
    float permutations = factorial(digitSize);
    int newIdx = std::floor(idx / permutations * digitSize);

    value.push_back(digits[newIdx]);
    digits.erase(digits.begin() + newIdx);
    idx = idx - permutations / digitSize * newIdx;
  }

  for (std::vector<int>::iterator i = value.begin(); i != value.end(); ++i) {
    std::cout << *i;
  }

  std::cout << std::endl;

  return 0;
}