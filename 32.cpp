#include <math.h>

#include <algorithm>
#include <iostream>
#include <set>
#include <string>

bool pandigitalValue(std::string str) {
  std::string sortedStr = str;
  std::sort(sortedStr.begin(), sortedStr.end());
  if (sortedStr == "123456789") {
    return true;
  }
  return false;
}

int main() {
  std::set<int> results;
  int max = 999999999;
  for (int i = 1; i < std::sqrt(max); ++i) {
    for (int j = i + 1; j < std::sqrt(max); ++j) {
      int prod = i * j;
      std::string val =
          std::to_string(j) + std::to_string(i) + std::to_string(prod);
      if (pandigitalValue(val)) {
        results.insert(prod);
      }
      if (val.length() > 9) {
        break;
      }
    }
  }

  int total = 0;
  for (std::set<int>::iterator i = results.begin(); i != results.end(); ++i) {
    total += *i;
  }
  std::cout << total << std::endl;
  return 0;
}