#include <iostream>


int sumSquare(int minVal, int maxVal) {
  int total = 0;
  for (minVal; minVal<= maxVal; ++minVal) {
    total += minVal * minVal;
  }
  return total;
}

int squareSum(int minVal, int maxVal) {
  int total = 0;
  for (minVal; minVal<= maxVal; ++minVal) {
    total += minVal;
  }
  return total * total;
}

int main() {
  int max = 100;
  int diff = squareSum(1, max) - sumSquare(1, max);
  std::cout << diff << std::endl;
  return 0;
}