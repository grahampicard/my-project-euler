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

std::string toBin(int num) {
  std::string buffer;
  while (num != 0) {
    buffer = (num % 2 == 0 ? "0" : "1") + buffer;
    num /= 2;
  }
  return buffer;
}

int main() {
  int total = 0;
  for (int i = 1; i < 1000000; ++i) {
    std::string stri = std::to_string(i);
    if (palindrome(stri)) {
      if (palindrome(toBin(i))) {
        total += i;
      };
    }
  }
  std::cout << total << std::endl;
  return 0;
}