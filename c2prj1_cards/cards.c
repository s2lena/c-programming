#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"


void assert_card_valid(card_t c) {
  assert (c.value >= 2 && c.value <= 14);
  assert (c.suit >= 0 && c.suit <= 3);
}

const char * ranking_to_string(hand_ranking_t r) {
  switch(r){
    case STRAIGHT_FLUSH:
      return "STRAIGHT_FLUSH";
      break;
    case FOUR_OF_A_KIND:
      return "FOUR_OF_A_KIND";
      break;
    case FULL_HOUSE:
      return "FULL_HOUSE";
      break;
    case FLUSH:
      return "FLUSH"; 
    case STRAIGHT:
      return "STRAIGHT";
      break;
    case THREE_OF_A_KIND:
      return "THREE_OF_A_KIND";
      break;
    case TWO_PAIR:
      return "TWO_PAIR";
      break;
    case PAIR:
      return "PAIR";
      break;
    case NOTHING:
      return "NOTHING";
      break;
    default:
      return "Invalid thing";
  }
}

char value_letter(card_t c) {
  char x = '0';
  if(c.value >= 2 && c.value <= 9) {
    x = x + c.value;
  }
  if(c.value == 11) {
    x = 'J';
  }
  if(c.value == 12) {
    x ='Q' ;
  }
  if(c.value == 13) {
    x = 'K' ;
  }
  if(c.value == 14) {
    x = 'A';
  }
  return x;
}

char suit_letter(card_t c) {
  char x ;
  switch(c.suit) {
    case SPADES:
      x = 's';
      break;
    case HEARTS:
      x = 'h';
      break;
    case DIAMONDS:
      x = 'd';
      break;
    case CLUBS:
      x = 'c';
      break;
    case NUM_SUITS:
      x = '?';
      break;
  }
  return  x ;
}
  
void print_card(card_t c) {
  int x = value_letter(c);
  char y = suit_letter(c);
  printf("%c%c", x, y);
}

 card_t card_from_letters(char value_let,char suit_let) {
  card_t temp;
  switch(value_let) {
    case '0':
      temp.value = 10;
      break;
    case 'J':
      temp.value = VALUE_JACK;
      break;
    case 'Q':
      temp.value = VALUE_QUEEN;
      break;
    case 'K':
      temp.value = VALUE_KING;
      break;
    case 'A':
      temp.value = VALUE_ACE;
      break;
    default:
      temp.value = value_let - '0';
      break;
  }
    switch(suit_let) {
      case 's':
	temp.suit = SPADES;
	break;
      case 'h':
	temp.suit = HEARTS;
	break;
      case 'd':
     	temp.suit = DIAMONDS;
	break;
      case 'c':
	temp.suit = CLUBS;
	break;
      default:
	temp.suit = NUM_SUITS;
	break;
  }
  return temp;
}
card_t card_from_num(unsigned c) {
  card_t temp;
  assert(0 <= c && c < 52);
  
  if(0 <= c && c < 13) {
    temp.suit = SPADES;
  } 
  else if(13 <= c && c < 26) {
    temp.suit = HEARTS;
  }
  else if(26 <= c && c < 39) {
    temp.suit = DIAMONDS;
  }
  else {
    temp.suit = CLUBS;
  }
  
  temp.value = c % 13 + 1;
  if(temp.value == 1) {
    temp.value = 14;
  }
  
  return temp;
}
