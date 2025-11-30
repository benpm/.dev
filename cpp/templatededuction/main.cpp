#include <iostream>

template<auto X>
int funcA() {
  return int(X) * int(X);
}

template<auto... X>
int funcB() {
  return 0;
}

int main() {
  std::cout << funcA<3>() << std::endl;
  std::cout << funcA<'a'>() << std::endl;
  std::cout << funcB<3, 4, 5, 6>() << std::endl;
  std::cout << funcB<'a'>() << std::endl;
}