#include <iostream>

uint symPair(uint a, uint b) {
  const uint x = a + b + 1;
  const uint minv = b ^ ((a ^ b) & -(a < b));
  return (((x * x) - (x & 1)) >> 2) + minv;
}
int main() {
  for (uint a = 0; a < 10; ++a)
    for (uint b = 0; b < 10; ++b) {
      std::cout << symPair(a, b) << " ";
      assert(symPair(a, b) == symPair(b, a));
    }
}