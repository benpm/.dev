#include <stdio.h>

void f(int* x) {
	int A[*x];
	int i;
	for (i = 0; i < *x; i++) {
		A[i] = i;
		printf("A[%d]=%d\n", i, A[i]);
	}
}

int main() {
	int i;
	for (i = 1; i < 12; i++) {
  	f(&i);
	}
}