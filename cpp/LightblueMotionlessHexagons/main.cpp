#include <iostream>

template <typename T>
struct A {
	template <typename K> A(T t, K k) {
		std::cout << t << k << std::endl;
	}

	std::string str() const {
		return "A";
	}
};

int main() {
	A<int> a = A<int>(1, 'c');
  std::cout << a.str() << std::endl;
}