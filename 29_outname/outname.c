#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "outname.h"

char * computeOutputFileName(const char * inputName) {
  //WRITE ME
  char * outFileName = malloc((strlen(inputName) + 7) * sizeof(*outFileName));
  strcpy(outFileName, inputName);
  strcat(outFileName, ".count");
  return outFileName;
}
