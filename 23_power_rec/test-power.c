#include <stdio.h>
#include <stdlib.h>

unsigned power(unsigned x, unsigned y);

void test(unsigned x, unsigned y, unsigned a) {
  printf("%d %d %d\n", x, y, a);
  if (power(x, y) != a) {
    exit(EXIT_FAILURE);
  }
}

int main() {
  test(1, 0, 1);

  test(2, 3, 8);

  test(0, 0, 1);

  test(0, 1, 0);

  test(1000000000, 1, 1000000000);
  return 0;
}




