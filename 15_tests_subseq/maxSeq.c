#include <stdio.h>

int max(int a, int b) {
  if (a > b) {
    return a;
  }
  return b;
}

size_t maxSeq(int* array, size_t n) {
  int length = 0;
  int max_length = 0;

  if (n == 0) {
    return 0;
  }

  for (int i = 0; i < n - 1; i++) {
    length++;
    if (array[i] >= array[i + 1]) {
      max_length = max(max_length, length);
      length = 0;
      }
  }
  max_length = max(max_length, length + 1);
  return max_length;
}
