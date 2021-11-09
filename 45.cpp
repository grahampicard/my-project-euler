#include <iostream>

// triangular
long T(long n) { return n * (n + 1) / 2; }

// pentagonal
long P(long n) { return n * (3 * n - 1) / 2; }

// hexagonal
long H(long n) { return n * (2 * n - 1); }

int main() {
  long curXh = 144, curXp = 165, curXt = 285;
  long curH = H(curXh), curP = P(curXp), curT = T(curXt);
  while (true) {
    ++curXh;
    curH = H(curXh);
    while (curP < curH){
      ++curXp;
      curP = P(curXp);
    }
    while (curT < curH) {
      ++curXt;
      curT = T(curXt);
    }
    if ((curH == curP) & (curP == curT)) {
      std::cout << curH << std::endl;
      return 0;
    }
  }
  return 0;
}