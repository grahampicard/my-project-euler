#include <iostream>

int factorial(int num) {
  int prod = 1;
  while (num > 0) {
    prod *= num;
    num -= 1;
  }
  return prod;
}

int main() {
  int sums = 0;

  for (int i = 3; i < 1000000; ++i) {
    int sum = 0;
    int val = i;

    while (val >= 1) {
      sum += factorial(val % 10);
      val = val / 10;
    }

    if (i == sum) {
      sums += sum;
    }
  }

  std::cout << sums << std::endl;

  return 0;
}
