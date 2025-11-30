#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
	char* str = (char*)malloc(1024);
	scanf("%s", str);
	printf("input string was '%s'", str);
	char* const args[] = {str};
	execvp(str, args);
  return 0;
}