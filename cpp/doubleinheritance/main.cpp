#include <iostream>

struct A {
  int x;
};

struct B1 : public A {
  int y;
};

struct B2 : public A {
  int z;
};

struct C : public B1, public B2 {
  int w;
};

int main() {
  C c;
  std::cout << "Hello World!\n";
}