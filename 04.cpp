// A palindromic number reads the same both ways. The largest palindrome made
// from the product of two 2-digit numbers is 9009 = 91 × 99.

// Find the largest palindrome made from the product of two 3-digit numbers.

#include <algorithm>
#include <iostream>
#include <string>

bool palindrome(std::string val) {
  std::string::iterator fwd_iter = val.begin();
  std::string::reverse_iterator bck_iter = val.rbegin();
  std::string::size_type half = val.size() / 2;
  std::string::size_type counter = 0;

  while (counter < half) {
    if (*fwd_iter != *bck_iter) {
      return false;
    }
    ++fwd_iter;
    ++bck_iter;
    ++counter;
  }

  return true;
}

int main() {
  int maxInt = 0;
  for (int i = 100; i < 1000; ++i) {
    for (int j = 100; j < 1000; ++j) {
      std::string strNum = std::to_string(i * j);
      if (palindrome(strNum)) {
        maxInt = std::max(maxInt, i * j);
      }
    }
  }
  std::cout << maxInt << std::endl;
}