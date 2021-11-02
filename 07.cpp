#include <iostream>

int isPrime(int n) {
  for (int i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

int findPrime(int primeN) {
  int primes = 0, counter = 1;

  while (primes < primeN) {
    ++counter;
    if (isPrime(counter)) {
      ++primes;
    }
  }
  return counter;
}

int main() {
  std::cout << findPrime(10001) << std::endl;
  return 0;
}