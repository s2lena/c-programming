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
  if (argc != 2 && argc != 3) {
    perror("Wrong input arguments\n");
    return EXIT_FAILURE;
  }
  FILE* f = fopen(argv[1], "r");
  if (f == NULL) {
    perror("Could not open file\n");
    return EXIT_FAILURE;
  }

  size_t n_hands = 0;
  future_cards_t* fc = malloc(sizeof(future_cards_t));
  fc->decks = NULL;
  fc->n_decks = 0;
  deck_t** hands = read_input(f, &n_hands, fc);

  if (fclose(f) != 0) {
    perror("Failed to close the input file!");
    return EXIT_FAILURE;
  }

  deck_t* remain_deck = build_remaining_deck(hands, n_hands);

  unsigned* win_arr = malloc((n_hands + 1) * sizeof(unsigned));
  for (int i = 0; i < n_hands + 1; i++) {
    win_arr[i] = 0;
  }

  unsigned n_trials = 10000;
  if (argc == 3) {
    n_trials = strtoul(argv[2], NULL, 0);
  }

  for (unsigned i = 0; i < n_trials; i++) {
    shuffle(remain_deck);
    future_cards_from_deck(remain_deck, fc);

    // find win hand
    deck_t* win_deck = hands[0];
    size_t win_idx = 0;
    for (size_t j = 1; j < n_hands; j++) {
      int result = compare_hands(win_deck, hands[j]);
      if (result < 0) {
	win_deck = hands[j];
	win_idx = j;
      }
      else if (result == 0) {
	win_idx = n_hands;
      }
    }
    win_arr[win_idx]++;
  }

  // print the win rate of each hand
  for (size_t i = 0; i < n_hands; i++) {
    printf("Hand %zu won %u / %u n_trials (%.2f%%)\n", i, win_arr[i], n_trials,
	   (float) win_arr[i] / n_trials * 100);
  }
  printf("And there were %u ties\n", win_arr[n_hands]);

  // free memory
  free(win_arr);
  free_deck(remain_deck);
  for (int i = 0; i < n_hands; i++) {
    free_deck(hands[i]);
  }
  free(hands);
  for (int i = 0; i < fc->n_decks; i++) {

    free(fc->decks[i].cards);
  }
  free(fc->decks);
  free(fc);
  return EXIT_SUCCESS;
}
