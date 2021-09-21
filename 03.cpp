// The prime factors of 13195 are 5, 7, 13 and 29.
// What is the largest prime factor of the number 600851475143 ?
#include <algorithm>
#include <iostream>
#include <list>

bool sieve(int &a, int &b) { return a > b; }

int main() {
  int number = 8;
  std::list<int> primes;
  std::list<int> factors;

  // take a number at a value
  // create a list with all possible values where mod = 0
  // loop until no nums left

  // data structures
  // int, prime list, nums list

  for (int i = 1; i < number; ++i) {
    if (number % i == 0) factors.push_back(i);
  }

  bool run = true;
  while (factors.size() > 0) {
    int num = factors.front();
    factors.pop_front();

    // if it's 1, append
    if (num == 1) {
      primes.push_back(num);
    }
  }
  return 0;
}
