#include <stdio.h>
#include <stdlib.h>

size_t maxSeq(int* array, size_t n);

void testMaxSeq(int i, int* array, size_t n, size_t expect) {
  if (maxSeq(array, n) != expect) {
    printf("Failed on %d\n", i);
    exit(EXIT_FAILURE);
  }
}

int main() {
  int test1[] = {};
  testMaxSeq(1, test1, 0, 0);

  int test2[] = {1};
  testMaxSeq(2, test2, 1, 1);

  int test3[] = {1, 2};
  testMaxSeq(3, test3, 2, 2);

  int test4[] = {2, 1};
  testMaxSeq(4, test4, 2, 1);

  int test5[] = {1, 1};
  testMaxSeq(5, test5, 2, 1);

  int test6[] = {1, 2, 4};
  testMaxSeq(6, test6, 3, 3);

  int test7[] = {4, 2, 1};
  testMaxSeq(7, test7, 3, 1);

  int test8[] = {1, 2, 1};
  testMaxSeq(8, test8, 3, 2);

  int test9[] = {-4, -2, -1};
  testMaxSeq(9, test9, 3, 3);

  int test10[] = {1, 2, 4, 1, 2};
  testMaxSeq(10, test10, 5, 3);

  int test11[] = {1, 2, 1, 2, 4};
  testMaxSeq(11, test11, 5, 3);

  int test12[] = {1, 2, -1, -2, -4};
  testMaxSeq(12, test12, 5, 2);

  return EXIT_SUCCESS;
}


