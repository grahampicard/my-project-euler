// The nth term of the sequence of triangle numbers is given by t_n = 1 / 2 * n
// * (n + 1); so the first ten triangle numbers are

// 1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...

// By converting each letter in a word to a number corresponding to its
// alphabetical position and adding these values we form a word value. For
// example, the word value for SKY is 19 + 11 + 25 == 55 = t_10. If the word
// value is a triangle number then we shall call the word a triangle word.

// Using a 16K text file containing nearly two-thousand common English words,
// how many are triangle words?

#include <iostream>
#include <string>
#include <vector>

// To find triangle words, we can use the general structure of the quadratic
// formula. Once we solve backward, we get t_n * 2 = n * (n + 1). This means we
// can iterate up to the square root of t_n, and multiply n * (n + 1). If this
// value equals t_n, this means it's a triangel number.
bool isTriangle(int t_n) {
  int n = 0;
  while ((n * n) <= t_n * 2) {
    if ((n * (n + 1)) == t_n * 2) {
      return true;
    }
    ++n;
  }
  return false;
}

int wordValue(std::string word) {
  int total = 0;
  for (std::string::iterator i = word.begin(); i != word.end(); ++i) {
    int letterVal = int(*i) - 'A' + 1;
    total += letterVal;
  }
  return total;
}

int main() {
  // TODO: update this vector to read in the PE file
  std::vector<std::string> words = {"SKY", "THE", "THIS", "THAT", "PLAY"};

  int triangles = 0;

  for (std::vector<std::string>::iterator i = words.begin(); i != words.end();
       ++i) {
    if (isTriangle(wordValue(*i))) {
      ++triangles;
    }
  }

  std::cout << triangles << std::endl;
  return 0;
}
