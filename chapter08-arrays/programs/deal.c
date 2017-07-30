// Deals a random hand of cards

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_SUITS 4 // Number of suits
#define NUM_RANKS 13 // Number of cards per suit
#define TRUE 1
#define FALSE 0

typedef int Bool;

int main() {

  // NOTE: this initialiser works for 2D array (missing will be 0)
  Bool in_hand[NUM_SUITS][NUM_RANKS] = {0}; // Tracks dealt cards

  int num_cards, rank, suit;
  // Constant face values of cards
  const char rank_code[] = {'2','3','4','5','6','7','8','9','t','j','q','k','a'};
  const char suit_code[] = {'c','d','h','s'};

  // Initialise a random number generator using current time,
  // to ensure it's different each time program is run
  srand((unsigned) time(NULL));

  printf("Enter number of cards in hand: ");
  scanf("%d", &num_cards);

  printf("Your hand:");
  while (num_cards > 0) {
    // Scale numbers to correct range
    suit = rand() % NUM_SUITS; // Pick a random suit
    rank = rand() % NUM_RANKS; // Pick a random rank
    if (!in_hand[suit][rank]) {
      in_hand[suit][rank] = TRUE; // Mark card as in hand
      num_cards--;
      printf(" %c%c", rank_code[rank], suit_code[suit]);
    }
  }
  printf("\n");
  return 0;
}
