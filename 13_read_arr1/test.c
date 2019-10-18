#include <stdio.h>
#include <stdlib.h>


int main(void) {
  int anArray[] = {5,16,33,99};
  int * p = anArray;
  printf("*p = %d\n", *p);
  p++;
  printf("Now *p = %d\n", *p);// *p = anArray[1]
  int * q = &anArray[3];// = 99
  int ** x = &q;// = anArray[3]
  **x = 12;// anArray[3] = 12
  *x = p;// q = p = anArray[1]
  **x = 42;// anArray[1] = 42
  q[1] = 9;// anArray[2] = 9; q[0] = anArray[1]
  for (int i =0; i < 4; i++){
    printf("anArray[%d] = %d\n",i, anArray[i]);
  }
  return EXIT_SUCCESS;
}
