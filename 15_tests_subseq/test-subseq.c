#include <stdio.h>
#include <stdlib.h>
size_t maxSeq (int * array, size_t n);

int main() {
  int test1[] = {4,5,-4,-3,-2,-1,1};
  if(maxSeq(test1, 6) != 4) {
    return EXIT_FAILURE;
  }
  int test2[] = {1};
  if(maxSeq(test2, 1) != 1) {
    return EXIT_FAILURE;
  }
  int test3[] = {};
  if(maxSeq(test3, 0) != 0) {
    return EXIT_FAILURE;
  }
  int test4[] = {4,3,2,1,0};
  if(maxSeq(test1, 5) != 1) {
    return EXIT_FAILURE;
  }
  int test5[] = {4,5,-4,-3,-2,-1,1};
  if(maxSeq(test1, 6) != 4) {
    return EXIT_FAILURE;
  }
  int test6[] = {1,2,3,4,5,6};
  if(maxSeq(test1, 6) != 3) {
    return EXIT_FAILURE;
  }
  int test7[] = {1,2,3,6,6,7};
  if(maxSeq(test1, 6) != 4) {
    return EXIT_FAILURE;
  }
  return 0;
}
