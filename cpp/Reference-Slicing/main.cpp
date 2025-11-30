//Casting references does not slice!

#include <iostream>

struct A {
  int x;
};

struct B : public A {
  int y;
};

int main() {
  B b;
  b.x = 10;
  b.y = 12;

  A& a = (A&)b;
  a.x = 2;

  B& c = (B&)a;
  std::cout << c.x << std::endl;
  std::cout << c.y << std::endl;

  return 0;
}