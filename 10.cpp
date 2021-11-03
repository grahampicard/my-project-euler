#include <cstring>
#include <iostream>

long sieveOfEratasthones(int max) {
  bool digits[max];
  std::memset(digits, true, max + 1);

  // 0 & 1 is not a prime
  digits[0] = false;
  digits[0] = false;
  long total = 0;

  for (int i = 1; i <= max; ++i) {
    if ((digits[i]) & (i >= 2)) {
      total += i;
      for (int j = i + i; j <= max; j += i) {
        if (j > i) digits[j] = false;
      }
    }
  }

  std::cout << total << std::endl;
  return 0;
}

int main() {
  sieveOfEratasthones(2000000);
  return 0;
}