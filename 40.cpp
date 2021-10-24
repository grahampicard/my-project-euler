// An irrational decimal fraction is created by concatenating the positive
// integers:

// 0.123456789101112131415161718192021...

// It can be seen that the 12th digit of the fractional part is 1.

// If dn represents the nth digit of the fractional part, find the value of the
// following expression.

// d1 × d10 × d100 × d1000 × d10000 × d100000 × d1000000

// instantiate the string to the max length
// loop through and get vals
// multiply together in the product

#include <iostream>
#include <string>
#define MAXLEN 1000000

int main() {
  std::string frac;
  int maxLength = MAXLEN;
  int i = 1;

  while (frac.length() <= maxLength) {
    frac += std::to_string(i);
    ++i;
  }

  int prod = 1;

  for (int i = 1; i <= MAXLEN; i = i * 10) {
    int ia = frac[i - 1] - '0';
    prod *= ia;
  }

  std::cout << prod << std::endl;

  return 0;
}