#include <iostream>
#include <memory>

struct A {
  int x;
  int y;
  int z;

  A(int x, int y, int z) {
    this->x = x;
    this->y = y;
    this->z = z;
  }
};

int main() {
  std::shared_ptr<A> a = std::make_shared<A>(1, 2, 3);
  A* a_ptr = a.get();
  std::shared_ptr<A> a2(a_ptr);
  std::cout << a.use_count() << std::endl;
  std::cout << a2.use_count() << std::endl;
  return 0;
}