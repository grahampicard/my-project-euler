#include <math.h>

#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

int main() {
  std::ifstream myfile("inputs/13.txt");
  std::string line;
  double total = 0;

  // read file and total results in a variable
  if (myfile.is_open()) {
    while (getline(myfile, line)) {
      double d = std::atof(line.c_str());
      total += d;
    }
    myfile.close();
  }

  // bring val to 10 digits
  while (total > std::pow(10, 10)) {
    total = total / 10;
  }

  // output results
  std::cout << std::setprecision(10) << total << std::endl;

  return 0;
}