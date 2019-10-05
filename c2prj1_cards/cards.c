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
    case SPADES: x = 'S';
      break;
    case HEARTS: x = 'H';
      break;
    case DIAMONDS: x = 'D';
      break;
    case CLUBS: x = 'C';
      break;
    case NUM_SUITS:
      x = 'N';
      break;
  }
  return  x ;
}
  
void print_card(card_t c) {
  int x = value_letter(c);
  char y = suit_letter(c);
  printf("My card is %c%c\n",x,y);
}

 card_t card_from_letters(char value_let,char suit_let) {
  card_t temp;
  switch(value_let) {
    case '0':
      temp.value = 10;
      break;
    case '2':
      temp.value = 2;
      break;
    case '3':
      temp.value = 3;
      break;
    case '4':
      temp.value = 4;
      break;
    case '5':
      temp.value = 5;
      break;
    case '6':
      temp.value = 6;
      break;
    case '7':
      temp.value = 7;
      break;
    case '8':
      temp.value = 8;
      break;
    case '9':
      temp.value = 9;
      break;
    case 'J':
      temp.value = 11;
      break;
    case 'Q':
      temp.value = 12;
      break;
    case 'K':
      temp.value = 13;
      break;
    case 'A':
      temp.value = 14;
      break;
    default:
      temp.value = 0;
      break;
  }
  switch(suit_let) {
    case 'S':
      temp.suit = 'S';
      break;
    case 'H':
      temp.suit = 'H';
      break;
    case 'D':
      temp.suit = 'D';
      break;
    case 'C':
      temp.suit = 'C';
      break;
    default:
      temp.suit = 'N';
      break;
  }
  return temp;
}
card_t card_from_num(unsigned c) {
  card_t temp;
  if(c >= 0 && c <= 12) {
    temp.suit = 'S';
  } 
  if(c > 12 && c <= 25) {
    temp.suit = 'H';
  }
  if(c > 25 && c <= 38) {
    temp.suit = 'D';
  }
  if(c > 38 && c <= 51) {
    temp.suit = 'C';
  }
  temp.value = c % 13;
  if(temp.value == 0) {
    temp.value = 13;
  }
  if(temp.value == 1) {
    temp.value = 14;
  }
  return temp;
}
