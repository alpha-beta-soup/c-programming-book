// Classsifies a poker hand

// Include directives
#include <stdio.h>
#include <stdlib.h>

// Define directtives
#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5
#define TRUE 1
#define FALSE 0

typedef int Bool;

// Declarations of external variables
int num_in_rank[NUM_RANKS];
int num_in_suit[NUM_SUITS];
Bool straight, flush, four, three;
int pairs; // Can be 0, 1, or 2

void read_cards(void);
void analyse_hand(void);
void print_result(void);
void check_for_flush(void);
void check_for_straight(void);
void check_for_n_of_a_kind(void);

// Main: calls read_cards, analyse_hand, and print_result repeatedly
int main() {
  for (;;) { //Infinite loop
    read_cards();
    analyse_hand();
    print_result();
  }
  exit(EXIT_SUCCESS);
}

// read_cards: Reads the cards into external variables; checks for bad
// cards and duplicate cards
void read_cards(void) {
  Bool card_exists[NUM_RANKS][NUM_SUITS];
  char ch, rank_ch, suit_ch;
  int rank, suit;
  Bool bad_card;
  int cards_read = 0;

  for (rank = 0; rank < NUM_RANKS; rank++) {
    num_in_rank[rank] = 0;
    for (suit = 0; suit < NUM_SUITS; suit++) {
      card_exists[rank][suit] = FALSE;
    }
  }

  for (suit = 0; suit < NUM_SUITS; suit++) {
    num_in_suit[suit] = 0;
  }

  while (cards_read < NUM_CARDS) {
    bad_card = FALSE;
    printf("Enter a card: ");

    rank_ch = getchar();
    switch (rank_ch) {
      case '0':           exit(EXIT_SUCCESS);
      case '2':           rank = 0; break;
      case '3':           rank = 1; break;
      case '4':           rank = 2; break;
      case '5':           rank = 3; break;
      case '6':           rank = 4; break;
      case '7':           rank = 5; break;
      case '8':           rank = 6; break;
      case '9':           rank = 7; break;
      case 't': case 'T': rank = 8; break; // 10
      case 'j': case 'J': rank = 9; break; // Jack
      case 'q': case 'Q': rank = 10; break; // Queen
      case 'k': case 'K': rank = 11; break; // King
      case 'a': case 'A': rank = 12; break; // Ace
      default:            bad_card = TRUE;
    }

    suit_ch = getchar();
    switch (suit_ch) {
      case 'c': case 'C': suit = 0; break; // Clubs
      case 'd': case 'D': suit = 1; break; // Diamonds
      case 'h': case 'H': suit = 2; break; // Hearts
      case 's': case 'S': suit = 3; break; // Spades
      default:            bad_card = TRUE;
    }

    while((ch = getchar()) != '\n') {
      if (ch != ' ') bad_card = TRUE;
    }
    if (bad_card) {
      printf ("Bad card: ignored.\n");
    } else if (card_exists[rank][suit]) {
      printf("Duplicate card; ignored.\n");
    } else {
      num_in_rank[rank]++;
      num_in_suit[suit]++;
      card_exists[rank][suit] = TRUE;
      cards_read++;
    }
  }
}

// analyse_hand: Determines whether the hand contains a straight, flush,
// four-of-a-kind, and/or three-of-a-kind; determines the number of pairs;
// stores the results into external variables
void analyse_hand(void) {
  flush = FALSE;
  straight = FALSE;
  four = FALSE;
  three = FALSE;
  pairs = 0;

  // Check for flush
  check_for_flush();
  // Check for straight
  check_for_straight();
  if (straight) {
    return;
  }
  // Check for 4-of-a-kind, 3-of-a-kind, and pairs
  check_for_n_of_a_kind();
}

// print_result: Notifies the user of the result, using the external
// variables set by analyse_hand
void print_result(void) {
  if (straight && flush)  printf("Straight flush\n\n");
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

void check_for_flush(void) {
  int suit;
  for (suit = 0; suit < NUM_SUITS; suit++) {
    if (num_in_suit[suit] == NUM_CARDS) {
      flush = TRUE;
      return;
    }
  }
  return;
}

void check_for_straight(void) {
  int rank = 0;
  int num_consec = 0;
  while (num_in_rank[rank] == 0) {
    rank++;
  }
  for (; rank < NUM_RANKS && num_in_rank[rank]; rank++) {
    num_consec++;
  }
  if (num_consec == NUM_CARDS) {
    straight = TRUE;
  }
  return;
}

void check_for_n_of_a_kind(void) {
  int rank;
  for (rank = 0; rank < NUM_RANKS; rank++) {
    if (num_in_rank[rank] == 4) {
      four = TRUE;
    }
    if (num_in_rank[rank] == 3) {
      three = TRUE;
    }
    if (num_in_rank[rank] == 2) {
      pairs++;
    }
  }
  return;
}
