#include <stdio.h>
#include <stdlib.h>
size_t maxSeq (int * array, size_t n);

int main() {
  int test1[] = {4,5,-4,-3,-2,-1,1};
  if(maxSeq(test1, 7) != 0) {
    return EXIT_FAILURE;
  }
  return 0;
}
