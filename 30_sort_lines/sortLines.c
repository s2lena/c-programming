#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This function is used to figure out the ordering
// of the strings in qsort.  You do not need
// to modify it.
int stringOrder(const void* vp1, const void* vp2) {
  const char* const* p1 = vp1;
  const char* const* p2 = vp2;
  return strcmp(*p1, *p2);
}
// This function will sort and print data (whose length is count).
void sortData(char** data, size_t count) {
  qsort(data, count, sizeof(char*), stringOrder);
}

size_t readData(char*** data, FILE* f) {
  char** lines = NULL;
  char* curr = NULL;
  size_t sz = 0;
  size_t n = 0;
  while (getline(&curr, &sz, f) >= 0) {
    lines = realloc(lines, (n + 1) * sizeof(char*));
    lines[n] = curr;
    curr = NULL;
    n++;
  }
  free(curr);
  *data = lines;
  return n;
}

void printData(char** data, size_t count) {
  for (int i = 0; i < count; i++) {
    printf("%s", data[i]);
    free(data[i]);
  }
}

int main(int argc, char** argv) {
  char** lines = NULL;
  FILE* f = NULL;
  size_t n = 0;
  if (argc == 1) {
    n = readData(&lines, stdin);
    sortData(lines, n);
    printData(lines, n);
    free(lines);
  } else {
    for (int i = 1; i < argc; i++) {
      f = fopen(argv[i], "r");
      if (f == NULL) {
        perror("Could not open file");
        return EXIT_FAILURE;
      }
      n = readData(&lines, f);
      sortData(lines, n);
      printData(lines, n);
      free(lines);
      if (fclose(f) != 0) {
        perror("Failed to close the input file!");
        return EXIT_FAILURE;
      }
    }
  }
  return EXIT_SUCCESS;
}

