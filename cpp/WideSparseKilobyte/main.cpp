#include <iostream>

void f(int x) {
	int A[x];
	for (int i = 0; i < x; i++) {
		A[i] = i;
		printf("A[%d]=%d\n", i, A[i])
	}
	
}

int main() {
  std::cout << "Hello World!\n";
}