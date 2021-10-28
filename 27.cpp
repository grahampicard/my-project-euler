// Considering quadratics of the form:
// N^2 + AN + B where |A| < 1000 and |B| <= 1000

// Where |N| is the modulus/absolute value of namespace
// Find the product of the coefficients an and b for the quadratic expression
// that produces the maximum number of primes for consecutive values of n

#include <math.h>

#include <iostream>

bool isPrime(int val) {
  if (val < 2) {
    return false;
  }

  int counter = 2;
  while (counter * counter <= val) {
    if (val % counter == 0) {
      return false;
    }
    ++counter;
  }
  return true;
}

bool quad(int& a, int& b, int& n) {
  int output = std::pow(n, 2) + a * n + b;
  return isPrime(output);
}

int consecutiveNs(int& a, int& b) {
  int n = 0;
  bool run = true;
  while (run) {
    if (quad(a, b, n)) {
      ++n;
    } else {
      run = false;
    }
  }
  return n;
}

int main() {
  std::cout << "Let's test the function" << std::endl;
  int a, b, n = 0;

  for (int ia = -1000; ia < 1000; ++ia) {
    for (int ib = -1000; ib <= 1000; ++ib) {
      int in = consecutiveNs(ia, ib);
      if (in > n) {
        a = ia, b = ib, n = in;
      }
    }
  }

  std::cout << a * b << std::endl;
  return 0;
}
