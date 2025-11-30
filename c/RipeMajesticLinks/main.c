#include <stdio.h>
#include <math.h>

float mod(float a, float b) {
  return a - b * floor(a / b);
}

float angle(float x, float y) {
  const float at = atan2(x, y);
  const float v = ((at + M_PI * 2.0f) * (at < 0.0f)) + (at * (at >= 0.0f));
  return mod(v - (M_PI * 0.50f), M_PI * 2.0f);
}

int main(void) {
  for (float i = 0; i < M_PI * 4.0f; i += M_PI * 0.25f) {
    float x = cos(i);
    float y = sin(i);
    printf("angle(%f,%f)=%f\n", x, y, angle(x, y));
  }
  return 0;
}