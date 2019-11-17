#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"

void print_hand(deck_t * hand){
  deck_t hands = * hand;
  size_t handSize = hand->n_cards;
  for (int i = 0; i <= (handSize - 1); i++) {
    card_t c = * (hands.cards[i]);
    print_card(c);
    printf(" ");
  }
}

int deck_contains(deck_t * d, card_t c) {
  size_t n = d->n_cards;
  deck_t decks = * d;
  for (size_t i = 0; i < n; i++) {
    card_t check = * (decks.cards[i]);
    if (check.value == c.value) {
      if (check.suit == c.suit) {
	return 1;
      }
    }
  }
  return 0;
}

void shuffle(deck_t * d){
  size_t n = d->n_cards;
  card_t ** ptr = d->cards;
  for (int i = 0; i <= n - 1; i++) {
    int k = rand()%((n - 1) - 0 + 1) + 0;
    card_t ** ptr1 = ptr + k;
    card_t ** ptr2 = ptr + i;
    card_t * temp = * ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
  } 
}

void assert_full_deck(deck_t * d) {
  for (int i = 0; i <= ((d->n_cards) - 1); i++) {
  assert((d->cards[i]->value) >= 2 || (d->cards[i]->value) <= 14);
  assert((d->cards[i]->suit) >= 0 || (d->cards[i]->suit) <= 3);
  }
}

