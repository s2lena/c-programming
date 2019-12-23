#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "counts.h"

counts_t* createCounts(void) {
  // WRITE ME
  counts_t* c = malloc(sizeof(counts_t));
  c->length = 0;
  c->unknown = 0;
  c->arr = NULL;
  return c;
}

void addCount(counts_t* c, const char* name) {
  // WRITE ME
  if (name == NULL) {
    c->unknown++;
  } else {
    int index = -1;
    for (int i = 0; i < c->length; i++) {
      if (strcmp(name, c->arr[i]->str) == 0) {
	index = i;
	break;
      }
    }
    if (index == -1) {
      c->length++;
      c->arr = realloc(c->arr, c->length * sizeof(counts_t));
      index = c->length - 1;
      c->arr[index] = malloc(sizeof(one_count_t));
      c->arr[index]->str = malloc(sizeof(char) * (strlen(name) + 1));
      strcpy(c->arr[index]->str, name);
      c->arr[index]->time = 0;
    }
    c->arr[index]->time += 1;
  }
}

void printCounts(counts_t* c, FILE* outFile) {
  // WRITE ME
  for (int i = 0; i < c->length; i++) {
    fprintf(outFile, "%s: %d\n", c->arr[i]->str, c->arr[i]->time);
  }
  if (c->unknown != 0) {
    fprintf(outFile, "<unknown> : %d\n", c->unknown);
  }
}

void freeCounts(counts_t* c) {
  // WRITE ME
  for (int i = 0; i < c->length; i++) {
    free(c->arr[i]->str);
    free(c->arr[i]);
  }
  free(c->arr);
  free(c);
}
