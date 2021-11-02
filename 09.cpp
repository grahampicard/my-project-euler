// Through algebra, we can make `a` a function of `b`.
//        a2 + b2 = (1000 - a - b)*(1000 - a - b)
//        a2 + b2 = 1000*1000 -1000a - 1000b
//                 +          -1000a          +a2 +ab
//                 +                 - 1000b      +ab + b2
//                = 1000000 - 2000a - 2000b + a2 + 2ab + b2
//              0 = 1000000 - 2000a - 2000b + 2ab
//     2a(1000-b) = 1000000 - 2000b
//             2a = (1000000 - 2000b) / (1000 - b)
//              a = (1/2) * (1000000 - 2000b) / (1000-b)
//              a = (500000 - 1000b) / (1000 - b)
//
// With this form, we now need to solve for a. We can do this by iterating
// through values of B until we find one where a == int(a)
#include <math.h>

#include <iostream>

float polynomial(float b) { return (500000 - 1000 * b) / (1000 - b); }

int main() {
  float b = 1;
  float a = polynomial(b);
  while (a != int(a)) {
    ++b;
    a = polynomial(b);
  }

  // print results
  int c = std::sqrt(a * a + b * b);
  std::cout << "A: " << a << std::endl
            << "B: " << b << std::endl
            << "C: " << c << std::endl;

  std::cout << std::endl << std::fixed << a * b * c << std::endl;
  return 0;
}
