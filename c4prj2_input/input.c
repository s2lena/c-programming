#include "future.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

deck_t* hand_from_string(const char* str, future_cards_t* fc) {
  deck_t* d = malloc(sizeof(deck_t));
  d->cards = NULL; int card_in_hand = 0;
  d->n_cards = 0;
  card_t c = {.value = 0, .suit = 0};
  int j = 0;
  char* card = malloc(2 * sizeof(char));
  for (int i = 0; i <= strlen(str) + 1; i++) {
    if (str[i] != ' ' && i != (strlen(str) + 1)) {
      card[j] = str[i];
      j++;
    }
    else {
      card_in_hand++;
      j = 0;
      c = card_from_letters(card[0], card[1]);
      if (c.suit != NUM_SUITS) {
	add_card_to(d, c);
      }
      else {
	size_t i = card[1] - '0';
	card_t* empty = add_empty_card(d);
	add_future_card(fc, i, empty);
      }
    }
  }
  if (card_in_hand < 5) {
    perror("Failed\n");
    return NULL;
  }
  free(card);
  return d;
}

deck_t** read_input(FILE* f, size_t* n_hands, future_cards_t* fc) {
  deck_t** arr_hand = malloc(sizeof(deck_t *));
  size_t lines = 0;
  char* curr = NULL;
  size_t sz = 0;
  while (getline(&curr, &sz, f) >= 0) {
    lines++;
    arr_hand = realloc(arr_hand, lines * sizeof(deck_t*));
    char* p = strchr(curr, '\n');
    if (p != NULL) {
      *p = '\0';
    }
    arr_hand[lines - 1] = malloc(sizeof(deck_t));
    arr_hand[lines - 1] = hand_from_string(curr, fc);
    free(curr);
    curr = NULL;
  }
  free(curr);
  *n_hands = lines;
  return arr_hand;
}
