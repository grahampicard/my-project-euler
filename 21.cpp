#include <iostream>
#include <numeric>
#include <vector>

using std::accumulate;
using std::cout;
using std::endl;
using std::vector;

int amicable(int n) {
  int i = 1;
  vector<int> divisors;

  while (i <= n / 2) {
    if (n % i == 0) {
      divisors.push_back(i);
    }
    ++i;
  }

  int sum = std::accumulate(divisors.begin(), divisors.end(), 0);

  return sum;
}

int main() {
  int amicable_sum;

  for (int i = 220; i < 10000; ++i) {
    int b = amicable(i);
    int db = amicable(b);

    if (i == db && i != b) {
      amicable_sum = amicable_sum + i;
    }
  }

  cout << amicable_sum << endl;
  return 0;
}