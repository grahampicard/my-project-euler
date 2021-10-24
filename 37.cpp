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

bool lTrunctable(int val) {
  std::string strval = std::to_string(val);

  while (strval.length() > 0) {
    if (!isPrime(std::stoi(strval))) {
      return false;
    }

    strval.erase(0, 1);
  }
  return true;
}

bool rTrunctable(int val) {
  std::string strval = std::to_string(val);

  while (strval.length() > 0) {
    if (!isPrime(std::stoi(strval))) {
      return false;
    }

    std::string::size_type len = strval.length();

    strval.erase(len - 1, 1);
  }
  return true;
}

int main() {
  int counter = 0;
  int total = 0;
  int start = 2;

  while (counter < 11) {
    if (lTrunctable(start)) {
      if (rTrunctable(start)) {
        if (start > 10) {
          ++counter;
          total += start;
        }
      }
    }
    ++start;
  }

  std::cout << total << std::endl;
  return 0;
}