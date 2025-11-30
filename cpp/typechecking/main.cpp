#include <iostream>
#include <memory>

class A {

};

class B : public A {

};

class C {

};

int main() {
  A a;
  B b;
  C c;
  if (typeid(a) == typeid(A)) {
    std::cout << "typeid(a) == typeid(A)" << std::endl;
  }
  if (typeid(std::dynamic_cast<A*>(b)) == typeid(A)) {
    std::cout << "typeid(b) == typeid(A)" << std::endl;
  }
  if (typeid(a) == typeid(B)) {
    std::cout << "typeid(a) == typeid(B)" << std::endl;
  }
}