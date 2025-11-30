#include <cassert>
#include <cmath>
#include <cstdio>
#include <iostream>

uint symPair(uint a, uint b) {
  const uint x = a + b + 1;
  const uint minv = b ^ ((a ^ b) & -(a < b));
  return (((x * x) - (x & 1)) >> 2) + minv;
}

int sign(int x) { return x == 0 ? 0 : (x > 0 ? 1 : -1); }

std::pair<uint32_t, uint32_t> symUnpair(int C) {
  const int t = (int)std::floor(std::sqrt(C));
  const int t2 = t * t;
  const int a = sign(C - t2);
  const int b = std::max(0, sign(t2 + t - C));
  const int c = t == 0 ? 0 : (t < 0 ? -1 : +1);
  int m = c * ((2 * t - 1) * (1 - a) + a * (t * (t + 3) - (t + 1) * b - C));
  int n = c * a * (C - t * (t + 1 - b));
  return {(uint32_t)m, (uint32_t)n};
}

int main() {
  for (uint a = 0; a < 10; ++a) {
    for (uint b = 0; b < 10; ++b) {
      printf("(%2u, %2u) %2u ", a, b, symPair(a, b));
      assert(symPair(a, b) == symPair(b, a));
      auto p = symUnpair(symPair(a, b));
      printf("(%2u, %2u)\n", p.first, p.second);
    }
  }
}