#include <stdio.h>

int main(void) {
  unsigned char a = 150;
  for (unsigned char i = 0; i < ('\2' * a); i++) {
    printf("%d\n", i);
  }
  return 0;
}