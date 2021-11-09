// The number, 1406357289, is a 0 to 9 pandigital number because it is made up
// of each of the digits 0 to 9 in some order, but it also has a rather
// interesting sub-string divisible property.

// Let d_1 be the 1st digit, d2 be the 2nd digit, and so on. In this way, we
// note the following: d2 * d3 * d4 = 602 is divisible by 2

// d3 * d4 * d5 = 063 is divisible by 3
// d4 * d5 * d6 = 653 is divisible by 5
// d5 * d6 * d7 = 357 is divisible by 7
// d6 * d7 * d8 = 572 is divisible by 11
// d7 * d8 * d9 = 728 is divislble by 13
// d8 * d9 * d10 = 289 is divisible by 17

// Find the sum of all 0 to 9 pandigital numbers with this property.

// Create some kind of iterator which generates pandigital numbers
// Create a boolean function which indicates whether it has this property or
// not. Sum up the values.

#include <algorithm>
#include <iostream>
#include <map>
#include <string>

std::map<int, int> PRIMEMAP = {
    {1, 2}, {2, 3}, {3, 5}, {4, 7}, {5, 11}, {6, 13}, {7, 17},
};

bool isSubstrDivisible(int pandigital) {
  std::string strNum = std::to_string(pandigital);
  for (int i = 1; i < 8; ++i) {
    // Include product here
    std::string subStr;
    for (int j = 1; j < 4; ++j) {
      subStr.push_back(strNum[i + j - 1]);
    }
    if (std::atoi(subStr.c_str()) % PRIMEMAP[i] != 0) {
      return false;
    }
  }
  return true;
}

bool pandigitalValue(std::string str) {
  std::string sortedStr = str;
  std::sort(sortedStr.begin(), sortedStr.end());
  if (sortedStr == "123456789") {
    return true;
  }
  return false;
}

int main() {
  int sum = 0;
  // Figure out how to make permutations in C++
  for (int i = 123456789; i < 999999999; ++i) {
    if (pandigitalValue(std::to_string(i))) {
      if (isSubstrDivisible(i)) {
        std::cout << i << std::endl;
        sum += i;
      }
    }
  }
  std::cout << sum << std::endl;
  return 0;
}