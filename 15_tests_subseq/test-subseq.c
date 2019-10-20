#include <stdio.h>
#include <stdlib.h>
size_t maxSeq (int * array, size_t n);

int main() {
  int test = maxSeq(int * array, size_t n);
  if(test == NULL) {
    printf("Fail\n");
  }
  else {
    printf("The max length is %d\n", test);
  }
  return 0;
}
