#include <iostream>
#include <map>

long divisors(long val) {
  std::map<int, int> primeMap;
  long n_divisors = 1;
  long number = 2;
  while (val > 1) {
    if (val % number == 0) {
      ++primeMap[number];
      val /= number;
    } else {
      ++number;
    }
  }

  for (std::map<int, int>::iterator i = primeMap.begin(); i != primeMap.end();
       ++i) {
    n_divisors *= (i->second + 1);
  }

  return n_divisors;
}

int main() {
  long current = 1;
  long triangle = current;
  long divs = divisors(triangle);

  while (divs < 500) {
    ++current;
    triangle += current;
    divs = divisors(triangle);
  }

  std::cout << triangle << std::endl;
  return 0;
}