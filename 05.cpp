// 2520 is the smallest number that can be divided by each of the numbers from 1
// to 10 without any remainder.

// What is the smallest positive number that is evenly divisible by all of the
// numbers from 1 to 20?

#include <iostream>

int main() {
  int vals = 1;

  while (true) {
    bool stop = true;
    for (int i = 1; i <= 20; ++i) {
      if (vals % i != 0) {
        ++vals;
        stop = false;
      }
    }
    if (stop) {
      std::cout << vals << std::endl;
      return 0;
    }
  }

  return 1;
}