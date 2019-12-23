#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"
#include "counts.h"
#include "outname.h"

counts_t * countFile(const char * filename, kvarray_t * kvPairs) {
  //WRITE ME
  FILE * f = fopen(filename, "r");
  if (f == NULL) {
    return NULL;
  }
  counts_t * c = createCounts();
  char * curr = NULL;
  size_t sz = 0;
  while (getline(&curr, &sz, f) >= 0) {
    char * p = strchr(curr, '\n');
    if (p != NULL) {
      *p = '\0';
    }
    char * name = lookupValue(kvPairs, curr);
    addCount(c, name);
    free(curr);
    curr = NULL;
    name = NULL;
  }
  free(curr);
  if (fclose(f) != 0) {
    return NULL;
  }
  return c;
}

int main(int argc, char ** argv) {
  //WRITE ME (plus add appropriate error checking!)
  if (argc <= 2) {
    return EXIT_FAILURE;
  }
  //read the key/value pairs from the file named by argv[1] (call the result kv)
  kvarray_t * kv = readKVs(argv[1]);
  if (kv == NULL) {
    return EXIT_FAILURE;
  }
  //count from 2 to argc (call the number you count i)
  for (int i = 2; i < argc; i++) {
    //count the values that appear in the file named by argv[i], using kv as the key/value pair
    //   (call this result c)
    counts_t * c = countFile(argv[i], kv);
    //compute the output file name from argv[i] (call this outName)
    char * outFileName = computeOutputFileName(argv[i]);
    //open the file named by outName (call that f)
    FILE * f = fopen(outFileName, "w");
    if ( f == NULL) {
      return EXIT_FAILURE;
    }
    //print the counts from c into the FILE f
    printCounts(c, f);
    //close f
    if (fclose(f) != 0) {
      return EXIT_FAILURE;
    }
    //free the memory for outName and c
    freeCounts(c);
    free(outFileName);
  }
  //free the memory for kv
  freeKVs(kv);
  return EXIT_SUCCESS;
}
