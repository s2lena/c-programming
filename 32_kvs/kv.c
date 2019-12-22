#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"

kvarray_t * readKVs(const char * fname) {
  //WRITE ME
  char * curr; size_t sz = 0;
  FILE * f = fopen(fname, "r");
  if (f == NULL) {
    return NULL;
  }
  kvarray_t * a = malloc(sizeof(kvarray_t));
  a->kvArr = NULL;
  int i = 0;
  while (getline(&curr, &sz, f) >= 0) {
    a->kvArr = realloc(a->kvArr, (i + 1) * sizeof(kvpair_t));
    a->kvArr[i] = malloc(sizeof(kvpair_t));
    a->kvArr[i]->key = NULL;
    a->kvArr[i]->value = NULL;
    int j = 0;
    while (curr[j] != '=') {
      a->kvArr[i]->key = realloc(a->kvArr[i]->key, (j + 1) * sizeof(char));
      a->kvArr[i]->key[j] = curr[j];
      j++;
    }
    a->kvArr[i]->key[j] = '\0';
    j++;
    int c = 0;
    while (curr[j] != '\n') {
      a->kvArr[i]->value = realloc(a->kvArr[i]->value, (c + 1) * sizeof(char));
      a->kvArr[i]->value[c] = curr[j];
      j++;
      c++;
    }
    a->kvArr[i]->value[c] = '\0';
    i++;
    curr = NULL;
  }
  a->length = i;
  return a;
}
void freeKVs(kvarray_t * pairs) {
  //WRITE ME
  for (int i = 0; i < pairs->length; i++) {
    free(pairs->kvArr[i]->key);
    free(pairs->kvArr[i]->value);
  }
  free(pairs->kvArr);
  free(pairs);
}

void printKVs(kvarray_t * pairs) {
  //WRITE ME
  for (int i = 0; i < pairs->length; i++) {
    printf("key = '%s' value = '%s'\n", pairs->kvArr[i]->key, pairs->kvArr[i]->value);
  }
}

char * lookupValue(kvarray_t * pairs, const char * key) {
  //WRITE ME
  for (int i = 0; i < (pairs->length); i++) {
    int a = 0; int check = 0;
    for (int j = 0; j < strlen(pairs->kvArr[i]->key); j++) {
      if (pairs->kvArr[i]->key[j] == key[a]) {
	a++;
	check = 0;
      }
      else {
	check = 1;
	j = j - a;
	a = 0;
      }
    }
    if (check == 0 && a == strlen(key)) {
      return pairs->kvArr[i]->value;
    }
  }
  return NULL;
}
