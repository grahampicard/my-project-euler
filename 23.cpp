#include <iostream>
#include <set>
#include <vector>

int type(int n) {
  int divisor_sum = 0;
  int i = 1;
  while (i <= n / 2) {
    if (n % i == 0) {
      divisor_sum = divisor_sum + i;
    }
    ++i;
  }

  if (divisor_sum > n) return 1;
  if (divisor_sum == n) return 0;
  return -1;
}

int main() {
  int cap = 28123;
  int i = 1;
  std::vector<int> abundants;
  std::vector<int> numbers;
  std::vector<int> vals;

  while (i <= cap) {
    if (type(i) == 1) {
      abundants.push_back(i);
    }
    numbers.push_back(i);
    ++i;
  }

  for (std::vector<int>::iterator i = abundants.begin(); i != abundants.end();
       ++i) {
    for (std::vector<int>::iterator j = numbers.begin(); i != numbers.end();
         ++j) {
    }
  }

  return 0;
}
