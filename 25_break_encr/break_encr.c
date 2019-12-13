#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int FindE(FILE * f) {
  int count[26]= {0};
  int c; int a; int max = 0;
  while ((c = fgetc(f)) != EOF) {
    if (isalpha(c)) {
      c = tolower(c);
      a = c - 'a';
      count[a]++;
    }
  }
  for (int i = 0; i < 26; i++) {
    int k = count[i];
    if (max < k) {
      max = k;
      a = 'a' + i;
    }
  }
  return a;
}

int FindKey(int word) {
  int k;
  if (word < 'e') {
    k = 26 + word - 'e';
  }
  else {
    k = word - 'e';
  }
  return k;
}

int main(int argc, char ** argv) {
  if (argc != 2) {
    fprintf(stderr,"Usage: encrypt key inputFileName\n");
    return EXIT_FAILURE;
  } 
  FILE * f = fopen(argv[1], "r");
  if (f == NULL) {
    perror("Could not open file");
    return EXIT_FAILURE;
  }
  int word = FindE(f);
  int key = FindKey(word);
  printf("%d\n", key);
  if (fclose(f) != 0) {
    perror("Failed to close the input file!");
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
