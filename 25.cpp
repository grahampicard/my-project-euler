#include <iostream>
#include <string>

int fibonacci(int val) {
  if (val < 3) {
    return -1;
  }

  std::string v1;
  std::string v2;
  std::string v3;
  int buffer;

  v1 = "39";
  v2 = "28";

  for (std::string::size_type i = v2.size(); i > 0; --i) {
    std::cout << v1[i - 1] << std::endl;
    std::cout << v2[i - 1] << std::endl;
    buffer = int(v2[i - 1]) - '0' + int(v1[i - 1]) - '0';

    if (buffer > 9) {
      v3 = std::to_string(buffer - 10);
    }

    std::cout << std::endl << std::endl << buffer << std::endl << std::endl;
  }

  return 3;
}

int main() {
  fibonacci(4);
  return 0;
}