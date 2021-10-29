#include <iostream>
#include <string>

std::string stringAdder(std::string a, std::string b) {
  std::string result;
  int ia = 0, ib = 0, carry = 0, value = 0;
  while ((a.length() > 0) || (b.length() > 0)) {
    if (a.length() > 0) {
      ia = a.back() - '0';
      a.pop_back();
    } else {
      ia = 0;
    }
    if (b.length() > 0) {
      ib = b.back() - '0';
      b.pop_back();
    } else {
      ib = 0;
    }
    int sum = ia + ib + carry;
    carry = sum / 10;
    value = sum % 10;
    result.insert(0, std::to_string(value));
  }
  if (carry > 0) {
    result.insert(0, std::to_string(carry));
  }
  return result;
}

int main() {

  int idx = 3;
  std::string i_1 = "1";
  std::string i_2 = "1";
  std::string i_3 = stringAdder(i_1, i_2);

  while (i_3.length() < 1000) {
    i_1 = i_2;
    i_2 = i_3;
    i_3 = stringAdder(i_1, i_2);
    ++idx;
  }

  std::cout << idx << std::endl;

  return 0;
}