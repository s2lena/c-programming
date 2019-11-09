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
  for (int i = 0; i <= ((d->n_cards) - 1); i++) {
    if (((d->cards[i]->value) == c.value) && ((d->cards[i]->suit) == c.suit)) {
      return 1;
    }
  }
  return 0;
}

void shuffle(deck_t * d){
  size_t n = (*d).n_cards;
  card_t ** ptc = (*d).cards;
  for(int i = n-1; i > 0; i--){

    int k = random()%(i+1);

    card_t ** ptc1 = ptc +n -1 -i;
    card_t ** ptc2 = ptc + k;
    card_t * temp = *ptc1;
    *ptc1 = *ptc2;
    *ptc2 = temp;
  }
}

void assert_full_deck(deck_t * d) {
  for (int i = 0; i <= ((d->n_cards) - 1); i++) {
    assert((d->cards[i]->value) < 2 || (d->cards[i]->value) > 14);
    assert((d->cards[i]->suit) < 0 || (d->cards[i]->suit) > 3);
  }
}
