#include "future.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void add_future_card(future_cards_t* fc, size_t index, card_t* ptr) {
  if (index >= fc->n_decks) {
    int n = fc->n_decks;
    fc->n_decks = index + 1;
    fc->decks = realloc(fc->decks, fc->n_decks * sizeof(deck_t));
    for (int j = n; j < fc->n_decks; j++) {
      fc->decks[j].n_cards = 0;
      fc->decks[j].cards = NULL;
    }
  }

  deck_t* d = &fc->decks[index];
  int i = d->n_cards;
  d->n_cards++;
  d->cards = realloc(d->cards, d->n_cards * sizeof(card_t));
  d->cards[i] = ptr;
}

void future_cards_from_deck(deck_t* deck, future_cards_t* fc) {
  for (size_t i = 0; i < fc->n_decks; i++) {
    if (fc->decks[i].n_cards == 0) {
      continue;
    }
    for (size_t j = 0; j < fc->decks[i].n_cards; j++) {
      *fc->decks[i].cards[j] = *deck->cards[i];
    }
  }
}
