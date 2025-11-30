#include <stdio.h>

int main(void) {
	int x = 7;
	int y = \
		x==3 ? 1 :\
		x==4 ? 2 :\
		x==5 ? 6 :\
		x==6 ? 7 : 99;
  	printf("y = %d\n", y);
  	return 0;
}