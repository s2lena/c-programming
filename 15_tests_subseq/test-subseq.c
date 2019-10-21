#include <stdio.h>
#include <stdlib.h>
size_t maxSeq (int * array, size_t n);

int main() {
  int array2[] = {2, 3, 4, 1, 2};
  if(maxSeq(array2, 5) != 5) {
    printf("Failed on 2, 3, 4, 1, 2\n");
    exit(EXIT_FAILURE);
  }
  int array1[] = {1, 2, 3, -1, -2, -3};
  if(maxSeq(array1, 6) != 3) {
    printf("Failed on 1, 2, 3, -1, -2, -3\n");
    exit(EXIT_FAILURE);
  }
  int array3[] = {1};
  if(maxSeq(array3, 1) != 0) {
    printf("Failed on 1\n");
    exit(EXIT_FAILURE);
  }
}
