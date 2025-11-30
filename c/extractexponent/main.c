#include <stdio.h>
#include <stdint.h>
#include <math.h>

int exponent(double x) {
  return (int)(0x7ff & ((*(uint64_t*)(&x)) >> 52)) - 1023;
}

int main(void) {
  printf("%d\n", exponent(1.0 * pow(2.0, 33)));
  printf("%d\n", exponent(0.1 * pow(2.0, 33)));
  printf("%d\n", exponent(1.1 * pow(2.0, 33)));
  return 0;
}