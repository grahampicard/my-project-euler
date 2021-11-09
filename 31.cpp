#include <iostream>
#include <map>
#include <vector>

int sumProduct(std::map<int, int> coins) {
  int total = 0;
  for (std::map<int, int>::iterator i = coins.begin(); i != coins.end(); ++i) {
    total += i->first * i->second;
  }
  return total;
}

int main() {
  std::map<int, int> a;
  a[3] = 4;
  a[4] = 2;
  a[5] = 9;
  std::cout << sumProduct(a) << std::endl;
  return 0;
}