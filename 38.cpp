#include <algorithm>
#include <iostream>
#include <string>

std::string pandigital(int val) {
  // log all sums to a string
  std::string products;
  int n = 1;

  // keep logging if the length of the sums is less than 9
  while (products.length() < 9) {
    int cur_prod = val * n;
    products += std::to_string(cur_prod);
    ++n;
  }

  return products;
}

int pandigitalValue(std::string str) {
  std::string sortedStr = str;
  std::sort(sortedStr.begin(), sortedStr.end());
  if (sortedStr == "123456789") {
    return std::stoi(str);
  }
  return 0;
}

int main() {
  // keep track of the max pandigital val
  int maxPandigital;
  int n = 2;

  while (n < 10000) {
    std::string prod = pandigital(n);
    int curValue = pandigitalValue(prod);
    if (curValue > 0) {
      maxPandigital = std::max(maxPandigital, curValue);
    }
    ++n;
  }
  std::cout << maxPandigital << std::endl;
  return 0;
}
