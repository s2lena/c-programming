#include <stdio.h>
#include <stdlib.h>

size_t maxSeq(int * array, size_t n) {
  int length = 0;
  int max = array[0];
  if(n == 0) {
    return NULL;
  }
  for(int i = 1; i < n; i++) {
    if(max < array[i]) {
      length += 1; 
    }
    else {
      length = 1;
    }
    max = array[i];
  }
  return length;
}
