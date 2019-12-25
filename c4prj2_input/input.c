#include "future.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

deck_t* hand_from_string(const char* str, future_cards_t* fc) {
  deck_t* d = malloc(sizeof(deck_t));
  d->cards = malloc(sizeof(card_t));
  d->n_cards = 0;
  card_t c = {.value = 0, .suit = 0};
  int j = 0;
  char* card = malloc(2 * sizeof(char));
  for (int i = 0; i <= strlen(str); i++) {
    if (str[i] != ' ' && i != strlen(str)) {
      card[j] = str[i];
      j++;
    }
    else {
      j = 0;
      c = card_from_letters(card[0], card[1]);
      if (c.suit != NUM_SUITS) {
	d->n_cards++;
	d->cards = realloc(d->cards, d->n_cards * sizeof(card_t));
	d->cards[d->n_cards - 1] = malloc(sizeof(card_t));
	d->cards[d->n_cards - 1]->suit = c.suit;
	d->cards[d->n_cards - 1]->value = c.value;
      }
      else {
	card_t * empty = malloc(sizeof(card_t));
	empty = add_empty_card(d);
	add_future_card(fc,(size_t)card[1], empty);
	free(empty);
      }
    }
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
