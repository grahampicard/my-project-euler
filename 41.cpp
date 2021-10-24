// We shall say that an n-digit number is pandigital if it makes use of all the
// digits 1 to n exactly once. For example, 2143 is a 4-digit pandigital and is
// also prime. What is the largest n-digit pandigital prime that exists?

// iterate through all numbers < 1000000000
// check if the number is prime
// check if the number is pandigital
//    convert to string
//    iterate through each letter, see if it matches the count #
//    if true return true

#include <algorithm>
#include <iostream>
#include <string>

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

bool isPandigital(int val) {
  std::string strval = std::to_string(val);
  sort(strval.begin(), strval.end());
  for (int i = 0; i < strval.length(); ++i) {
    int letter = strval[i] - '0';
    if (letter != i + 1) {
      return false;
    }
  }
  return true;
}

int main() {
  int maxPrimePandigital;
  for (int i = 1; i < 1000000000; ++i) {
    if (isPrime(i)) {
      if (isPandigital(i)) {
        maxPrimePandigital = i;
      }
    }
  }
  std::cout << maxPrimePandigital << std::endl;
  return 0;
}