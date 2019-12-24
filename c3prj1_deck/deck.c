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

void add_card_to(deck_t* deck, card_t c) {
  int index = deck->n_cards;
  deck->n_cards++;
  deck->cards = realloc(deck->cards, deck->n_cards * sizeof(card_t));
  deck->cards[index] = malloc(sizeof(card_t));
  deck->cards[index]->value = c.value;
  deck->cards[index]->suit = c.suit;
}

card_t* add_empty_card(deck_t* deck) {
  card_t* c = malloc(sizeof(card_t));
  c->suit = 0;
  c->value = 0;
  int index = deck->n_cards;
  deck->n_cards++;
  deck->cards = realloc(deck->cards, deck->n_cards * sizeof(card_t));
  deck->cards[index] = c;
  return c;
}

deck_t* make_deck_exclude(deck_t* excluded_cards) {
  deck_t * d = malloc(sizeof(deck_t));
  d->n_cards = 0; card_t c = {.value = 0, .suit = 0}
  for (int i = 0; i < 13; i++) {
    for (int j = 0; j < 4; j++) {
      c = card_from_num(i + (13 * j));
      if (deck_contains(excluded_cards, c) == 1){
	continue;
      }
      add_card_to(d, c);
    }
  }
  return d;
}

deck_t * build_remaining_deck(deck_t ** hands, size_t n_hands) {
  deck_t * excluded = malloc(sizeof(deck_t));
  excluded->n_cards = 0;
  for (int i = 0; i < n_hands; i++) {
    for (int j = 0; j < hands[i]->n_cards; j++) {
      card_t c;
      c.value = hands[i]->cards[j]->value;
      c.suit = hands[i]->cards[j]->suit;
      add_card_to(excluded, c);
    }
  }
  deck_t * d = make_deck_exclude(excluded);
  return d;
}

void free_deck(deck_t * deck) {
  for (int i = 0; i < deck->n_cards; i++) {
    free(deck->cards[i]);
  }
  free(deck->cards);
  free(deck);
}
