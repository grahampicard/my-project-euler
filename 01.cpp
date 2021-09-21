#include <iostream>

int main() {
  int cap = 1000;
  int sum = 0;

  for (int i = 0; i < cap; ++i) {
    if (i % 3 == 0) {
      sum += i;
    } else {
      if (i % 5 == 0) {
        sum += i;
      }
    }
  }
  std::cout << sum << std::endl;
  return 0;
}