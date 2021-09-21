#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

typedef std::pair<std::string, int> namePair;

bool sortName(const namePair &a, const namePair &b) {
  return a.first < b.first;
}

int main() {
  std::string line;
  std::ifstream myfile("inputs/p022_names.txt");
  std::vector<namePair> namePairs;

  // read file in and instantiate name vector
  if (myfile.is_open()) {
    while (myfile.good()) {
      getline(myfile, line);
      std::string nameBuf;
      int nameSum = 0;
      for (std::string::iterator i = line.begin(); i != line.end(); ++i) {
        if (*i == ',') {
          namePair p = {nameBuf, nameSum};
          namePairs.push_back(p);
          nameBuf.clear();
          nameSum = 0;
        } else {
          if (*i != '"') {
            nameBuf.push_back(*i);
            nameSum += int(*i) - 64;
          }
        }
      }
      namePair p = {nameBuf, nameSum};
      namePairs.push_back(p);
    }
    myfile.close();
  }

  // calculate sum of names
  int total = 0;
  std::sort(namePairs.begin(), namePairs.end(), sortName);

  for (std::vector<namePair>::size_type i = 0; i < namePairs.size(); ++i) {
    total += namePairs[i].second * (i + 1);
  }

  std::cout << total << std::endl;

  return 0;
}
