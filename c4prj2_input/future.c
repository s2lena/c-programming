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
  if (deck->n_cards != fc->n_decks) {
    perror("Failed\n");
    return;
  }
  if (fc->n_decks == 0) {
    perror("No future card\n");
    return;
  }
  for (int i = 0; i < deck->n_cards; i++) {
    for (int j = 0; j < fc->decks[i].n_cards; i++) {
      fc->decks[i].cards[j]->value = deck->cards[i]->value;
      fc->decks[i].cards[j]->suit = deck->cards[i]->suit;
    }
  }
}
