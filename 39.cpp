// If p is the perimeter of a right angle triangle with integral length sides,
// {a,b,c}, there are exactly three solutions for p = 120.

// {20,48,52}, {24,45,51}, {30,40,50}

// For which value of p ≤ 1000, is the number of solutions maximised?

// Take an integer (<1000)
// Loop through second integers (< 1000)
// Perform P theorem, find c
// if c is integer, do a max check on the sum of values
// ensure b is greater than a.
// incrment map by 1

#include <math.h>

#include <algorithm>
#include <iostream>
#include <map>

float pythagorean(int a, int b) {
  return std::sqrt(std::pow(a, 2) + std::pow(b, 2));
}

bool integerCheck(float a) {
  if (std::ceil(a) == a) return true;
  return false;
}

int main() {
  std::map<int, int> perimiters;
  for (int a = 1; a <= 1000; ++a) {
    for (int b = a; b <= 1000; ++b) {
      float c = pythagorean(a, b);
      if (integerCheck(c)) {
        int p = a + b + c;
        if (p <= 1000) {
          perimiters[p] += 1;
        }
      }
    }
  }

  int maxCounts = 0;
  int maxP = 0;

  for (std::map<int, int>::iterator i = perimiters.begin();
       i != perimiters.end(); ++i) {
    if (i->second >= maxCounts) {
      maxCounts = i->second;
      maxP = i->first;
    }
  }

  std::cout << maxP << std::endl;
  return 0;
}
