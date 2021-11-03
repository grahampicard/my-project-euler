#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

std::vector<int> splitRow(std::string input) {
  std::vector<int> row;
  std::string buffer;
  for (std::string::iterator i = input.begin(); i != input.end(); ++i) {
    if (*i != ' ') {
      buffer.push_back(*i);
      continue;
    }
    row.push_back(std::stoi(buffer));
    buffer.clear();
  }
  row.push_back(std::stoi(buffer));
  buffer.clear();

  return row;
}

int main() {
  std::ifstream inputFile("./inputs/11.txt");
  std::string myString;
  std::vector<std::vector<int>> matrix;

  // create an internal representation of the 20x20 matrix
  while (std::getline(inputFile, myString)) {
    matrix.push_back(splitRow(myString));
  }

  long maxProd = 0;

  // check the max for left-right
  for (int i = 0; i < matrix.size(); ++i) {
    for (int j = 0; j < matrix[0].size() - 3; ++j) {
      long prod = 1;
      for (int x = j; x < j + 4; ++x) {
        prod *= matrix[i][x];
      }
      maxProd = std::max(maxProd, prod);
    }
  }

  // check the max for up-down
  for (int i = 0; i < matrix.size() - 3; ++i) {
    for (int j = 0; j < matrix[0].size(); ++j) {
      long prod = 1;
      for (int x = i; x < i + 4; ++x) {
        prod *= matrix[x][j];
      }
      maxProd = std::max(maxProd, prod);
    }
  }

  // check the max for diag-left
  for (int i = 0; i < matrix.size() - 3; ++i) {
    for (int j = 0; j < matrix[0].size() - 3; ++j) {
      long prod = 1;
      for (int x = 0; x < 4; ++x) {
        prod *= matrix[i + x][j + x];
      }
      maxProd = std::max(maxProd, prod);
    }
  }

  // check the max for diag-left
  for (int i = matrix.size() - 1; i > 3; --i) {
    for (int j = 0; j < matrix.size() - 3; ++j) {
      long prod = 1;
      for (int x = 0; x < 4; ++x) {
        prod *= matrix[i - x][j + x];
      }
      maxProd = std::max(maxProd, prod);
    }
  }

  std::cout << maxProd << std::endl;

  return 0;
}
