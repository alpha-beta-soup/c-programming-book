// Classsifies a poker hand

// Include directives
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Define directtives
#define RANK 0
#define SUIT 1
#define NUM_CARDS 5

// Declarations of external variables
bool royal_flush, straight, flush, four, three;
int pairs; // Can be 0, 1, or 2

void read_cards(int hand[][2]);
void analyse_hand(int hand[][2]);
void print_result(void);
bool card_exists(int hand[][2], int rank, int suit);
void check_for_flush(int hand[][2]);
void check_for_straight(int sorted_hand_ranks[]);
void check_for_royal_flush(int hand[][2], int sorted_hand_ranks[]);
int get_high_rank(int sorted_hand_ranks[]);
int get_low_rank(int sorted_hand_ranks[]);
void check_for_n_of_a_kind(int hand[][2]);
void selectionsort(int a[], int length);
int index_of_max(int a[], int length);

// Main: calls read_cards, analyse_hand, and print_result repeatedly
int main() {
  int hand[NUM_CARDS][2];
  for (;;) { //Infinite loop
    read_cards(hand);
    analyse_hand(hand);
    print_result();
  }
  exit(EXIT_SUCCESS);
}

// read_cards: Reads the cards into external variables; checks for bad
// cards and duplicate cards
void read_cards(int hand[][2]) {
  char ch;
  int rank, suit;
  bool bad_card;
  int cards_read = 0;

  for (cards_read = 0; cards_read < NUM_CARDS; cards_read++) {
    hand[cards_read][RANK] = hand[cards_read][SUIT] = 0;
  }

  cards_read = 0;

  while (cards_read < NUM_CARDS) {
    bad_card = false;
    printf("Enter a card: ");

    switch (toupper(getchar())) {
      case '0': exit(EXIT_SUCCESS);
      case '2': rank = 2; break;
      case '3': rank = 3; break;
      case '4': rank = 4; break;
      case '5': rank = 5; break;
      case '6': rank = 6; break;
      case '7': rank = 7; break;
      case '8': rank = 8; break;
      case '9': rank = 9; break;
      case 'T': rank = 10; break; // 10
      case 'J': rank = 11; break; // Jack
      case 'Q': rank = 12; break; // Queen
      case 'K': rank = 13; break; // King
      case 'A': rank = 14; break; // Ace
      default:  bad_card = true;
    }

    switch (toupper(getchar())) {
      case 'C': suit = 1; break; // Clubs
      case 'D': suit = 2; break; // Diamonds
      case 'H': suit = 3; break; // Hearts
      case 'S': suit = 4; break; // Spades
      default:  bad_card = true;
    }

    while((ch = getchar()) != '\n') {
      if (ch != ' ') bad_card = true;
    }
    if (bad_card) {
      printf ("Bad card: ignored.\n");
    } else if (card_exists(hand, rank, suit)) {
      printf("Duplicate card; ignored.\n");
    } else {
      hand[cards_read][RANK] = rank;
      hand[cards_read][SUIT] = suit;
      cards_read++;
    }
  }
}

// analyse_hand: Determines whether the hand contains a straight, flush,
// four-of-a-kind, and/or three-of-a-kind; determines the number of pairs;
// stores the results into external variables
void analyse_hand(int hand[][2]) {
  flush = false;
  straight = false;
  four = false;
  three = false;
  pairs = 0;

  int ranks[NUM_CARDS] = {0};
  // Collect the hand's card ranks
  for (int card = 0; card < NUM_CARDS; card++) {
    ranks[card] = hand[card][RANK];
  }
  // Sort the cards by rank
  selectionsort(ranks, NUM_CARDS);

  // Check for royal flush, flush, and straight
  check_for_royal_flush(hand, ranks);
  // Check for 4-of-a-kind, 3-of-a-kind, and pairs
  check_for_n_of_a_kind(hand);
}

// print_result: Notifies the user of the result, using the external
// variables set by analyse_hand
void print_result(void) {
  if (royal_flush)        printf("Royal flush\n\n");
  else if (straight &&
           flush)         printf("Straight flush\n\n");
  else if (four)          printf("Four of a kind\n\n");
  else if (three &&
           pairs == 1)    printf("Full house\n\n");
  else if (flush)         printf("Flush\n\n");
  else if (straight)      printf("Straight\n\n");
  else if (three)         printf("Three of a kind\n\n");
  else if (pairs == 2)    printf("Two pairs\n\n");
  else if (pairs == 1)    printf("Pair\n\n");
  else                    printf("High card\n\n");
}

void check_for_flush(int hand[][2]) {
  int card;
  for (card = 0; card < NUM_CARDS; card++) {
    if (hand[0][SUIT] != hand[card][SUIT]) {
      flush = false;
      return;
    }
  }
  flush = true;
  return;
}

void check_for_royal_flush(int hand[][2], int sorted_hand_ranks[]) {
  check_for_flush(hand);
  check_for_straight(sorted_hand_ranks);
  // Check both high and low, because an ace can be low (ace-low straight)
  royal_flush = flush && straight &&
                get_high_rank(sorted_hand_ranks) == 14 &&
                get_low_rank(sorted_hand_ranks) == 10 ?
                true : false;
}

void check_for_straight(int sorted_hand_ranks[]) {
  // Check the hand is monotically increasing
  for (int card = 1; card < NUM_CARDS; card++) {
    if (sorted_hand_ranks[card] != sorted_hand_ranks[card - 1] + 1) {
      // Allow special case of ace-low straights (2, 3, 4, 5, A)
      if (!(sorted_hand_ranks[card -1] == 5 && sorted_hand_ranks[card] == 14)) {
        return;
      }
    }
  }
  straight = true;
}

void check_for_n_of_a_kind(int hand[][2]) {
  for (int card1 = 0; card1 < NUM_CARDS; card1++) {
    int rank = hand[card1][RANK];
    int matches = 1;
    for (int card2 = card1 + 1; card2 < NUM_CARDS; card2++) {
      if (rank == hand[card2][RANK]) {
        matches++;
      }
    }
    if (matches == 4) {
      four = true;
      return;
    }
    if (matches == 3) {
      three = true;
      return;
    }
    if (matches == 2) {
      pairs++;
    }
  }
  return;
}

bool card_exists(int hand[][2], int rank, int suit) {
  for (int card = 0; card < NUM_CARDS; card++) {
    if (hand[card][RANK] == rank && hand[card][SUIT] == suit) {
      return true;
    }
  }
  return false;
}

int get_high_rank(int sorted_hand_ranks[]) {
  return sorted_hand_ranks[NUM_CARDS-1];
}

int get_low_rank(int sorted_hand_ranks[]) {
  return sorted_hand_ranks[0];
}

void selectionsort(int a[], int n) {
  if (n > 1) {
    // Move the largest element to the end of the unsorted sublist
    // Replacing it with what is in that place
    int last;
    int max_index = index_of_max(a, n);
    last = a[n-1];
    a[n-1] = a[max_index];
    a[max_index] = last;
    selectionsort(a, --n);
  }
  return;
}

int index_of_max(int a[], int n) {
  int i;
  int max = a[0];
  int max_index = 0;
  for (i = 1; i < n; i++) {
    if (a[i] > max) {
      max = a[i];
      max_index = i;
    }
  }
  return max_index;
}
