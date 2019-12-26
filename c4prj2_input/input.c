#include "future.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>

deck_t* hand_from_string(const char* str, future_cards_t* fc) {
  deck_t* d = malloc(sizeof(deck_t));
  d->cards = NULL;
  d->n_cards = 0;
  for (int i = 0; i < strlen(str); i++) {
    if (isspace(str[i])) {
      continue;
    }
    if (str[i] == '?' && isdigit(str[i + 1]) != 0) {
      char num[5];
      int j = 0;
      i++;
      while (isdigit(str[i])) {
	num[j] = str[i];
	j++;
	i++;
      }
      num[j] = '\0';
      size_t idx = strtoul(num, NULL, 0);
      add_future_card(fc, idx, add_empty_card(d));
    } else {
      card_t c = card_from_letters(str[i], str[i + 1]);
      add_card_to(d, c);
      i++;
    }
  }
  if (d->n_cards < 5) {
    perror("Failed\n");
    return NULL;
  }
  return d;
}

deck_t** read_input(FILE* f, size_t* n_hands, future_cards_t* fc) {
  deck_t** arr_hand = malloc(sizeof(deck_t*));
  size_t lines = 0;
  char* curr = NULL;
  size_t sz = 0;
  while (getline(&curr, &sz, f) >= 0) {
    char* p = strchr(curr, '\n');
    if (p != NULL) {
      *p = '\0';
    }
    lines++;
    arr_hand = realloc(arr_hand, lines * sizeof(deck_t*));
    arr_hand[lines - 1] = hand_from_string(curr, fc);
    free(curr);
    curr = NULL;
  }
  free(curr);
  *n_hands = lines;
  return arr_hand;
}
