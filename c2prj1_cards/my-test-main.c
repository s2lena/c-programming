#include "cards.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  card_t c;
  c.value = 11;
  c.suit = 2;
  assert_card_valid(c);
  printf("My ranking is %s\n", ranking_to_string(FLUSH));
  printf("My value is %c\n", value_letter(c));
  printf("My suit is %c\n", suit_letter(c));
  print_card(c);
  card_t x = card_from_letters('8','H');
  printf("For %d of %d\n", x.value, x.suit);
  card_t y = card_from_num(36);
  printf("For %d of %c \n", y.value, y.suit);
  
  return 0;
}
