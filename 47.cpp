#include <iostream>
#include <map>
#include <vector>

std::vector<int> divisors(long val) {
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

  std::vector<int> output;
  for (std::map<int, int>::iterator i = primeMap.begin(); i != primeMap.end();
       ++i) {
    output.push_back(i->first);
    std::cout << i->first << std::endl;
  }

  return output;
}

int main() {
  std::vector<int> a = divisors(15);
  return 0;
}