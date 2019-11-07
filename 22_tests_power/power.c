#include <stdio.h>
#include <stdlib.h>

unsigned power(unsigned x, unsigned y) {
  unsigned p;
  if (x == 0 && y == 0) {
    p = 1;
  }
  else if (x == 0) {
    p = 0;
  }
  else {
    for (int i = 1; i <= y; i++) {
      p = p * x;
    }
  }
  return p;
}
