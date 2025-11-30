#include <stdio.h>
#include <stdbool.h>

typedef union {
	bool boolval;
	float floatval;
} Foo;

int main(void) {
	Foo foo1;
	Foo foo2;
	foo1.floatval = 1.0f;
	foo2.boolval = true;
	float foo1_cast = foo1.floatval;
	float foo2_cast = foo2.floatval;
	printf("foo1_cast = %f\n", foo1_cast);
	printf("foo2_cast = %f\n", foo2_cast);
  return 0;
}