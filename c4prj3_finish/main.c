#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include "cards.h"
#include "deck.h"
#include "eval.h"
#include "future.h"
#include "input.h"

int main(int argc, char** argv) {
  // YOUR CODE GOES HERE
  if (argc > 3) {
    perror("Too much input arguments\n");
    return EXIT_FAILURE;
  }
  FILE* f = fopen(argv[1], "r");
  if (f == NULL) {
    perror("Could not open file\n");
    return EXIT_FAILURE;
  }
  size_t n_hand = 0;
  size_t* n_hands = &n_hand;
  unsigned times;
  future_cards_t* fc = malloc(sizeof(future_cards_t));
  fc->decks = NULL;
  fc->n_decks = 0;
  deck_t** hand = read_input(f, n_hands, fc);
  deck_t* remainDeck = build_remaining_deck(hand, *n_hands);
  unsigned* array = malloc((*n_hands + 1) * sizeof(unsigned));
  for (int j = 0; j < *n_hands + 1; j++) {
    array[j] = 0;
  }
  if (argc == 2)
    times = 10000;
  else {
    times = strtoul(argv[2], NULL, 0);
  }
  for (unsigned j = 0; j < times; j++) {
    shuffle(remainDeck);
    future_cards_from_deck(remainDeck, fc);
    deck_t* predeck = hand[0];
    int t = 0;
    size_t idx = 0;
    for (size_t e = 1; e < *n_hands; e++) {
      t = compare_hands(predeck, hand[e]);
      if (t < 0) {
	predeck = hand[e];
	idx = e;
      }
    }
    if (t != 0) {
      array[idx]++;
    } else {
      array[*n_hands]++;
    }
  }
  for (size_t j = 0; j < *n_hands; j++) {
    printf("Hand %zu won %u / %u times (%.2f%%)\n", j, array[j], times,
	   ((float)array[j] / (float)times) * 100);
  }
  printf("And there were %u ties\n", array[*n_hands]);
  if (fclose(f) != 0) {
    perror("Failed to close the input file!");
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
