#include <math.h>

#include <cstring>
#include <iostream>
#include <vector>

bool isPrime(int n) {
  for (int i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

std::vector<bool> sieveOfEratasthones(int max) {
  // 0 & 1 is not a prime
  std::vector<bool> digits(max, true);
  digits.push_back(false);
  long total = 0;

  for (int i = 1; i <= max; ++i) {
    if ((digits[i]) & (i >= 2)) {
      total += i;
      for (int j = i + i; j <= max; j += i) {
        if (j > i) digits[j] = false;
      }
    }
  }

  return digits;
}

bool checkFormula(int val, int prime) {
  float fVal = (val - prime);
  fVal = std::sqrt(fVal / 2);
  if (fVal == int(fVal)) {
    return true;
  }
  return false;
}

bool checkGoldbach(int val) {
  int counter = 0;
  std::vector<bool> primes = sieveOfEratasthones(val);
  for (std::vector<bool>::iterator i = primes.begin(); i != primes.end(); ++i) {
    if (counter > 2) {
      if (*i) {
        if (checkFormula(val, counter)) {
          return true;
        }
      }
    }
    ++counter;
  }
  return false;
}

int main() {
  int start = 9;
  while (true) {
    if ((!isPrime(start)) & (start % 2 == 1)) {
      if (!checkGoldbach(start)) {
        std::cout << start << std::endl;
        return 0;
      }
    }
    ++start;
  }
  return 1;
}
