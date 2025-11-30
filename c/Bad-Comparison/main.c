#include <stdio.h>

int main(void) {
  double v = -0.01;
  printf("%lf == %d -> %d\n", v, 0, v == 0);
  return 0;
}