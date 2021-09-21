#include <iostream>

int main() {
  int cap = 4000000;
  int sum = 0;
  int i = 1;
  int ii = 2;
  int buffer = 3;

  while (i < cap) {
    if (i % 2 == 0) {
      sum += i;
    }
    i = ii;
    ii = buffer;
    buffer = ii + i;
  }
  std::cout << sum << std::endl;
  return 0;
}