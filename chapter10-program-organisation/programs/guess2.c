// Asks users to guess a hidden number

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBER 1000

int secret_number;

void initialise_number_generator(void);
int new_secret_number(void);
void read_guesses(int secret_number);

int main() {
  char command;
  int secret_number;

  printf("Guess the secret number between 1 and %d.\n\n", MAX_NUMBER);
  initialise_number_generator();
  do {
    secret_number = new_secret_number();
    printf("A new number has been chosen.\n");
    read_guesses(secret_number);
    printf("Play again? (Y/N)");
    scanf(" %c", &command);
    printf("\n");
  } while (command == 'y' || command == 'Y');
  return 0;
}

// Initialises the random number generator using the time of day
void initialise_number_generator(void) {
  srand((unsigned) time(NULL));
}

// Randomly selects a number between 1 and MAX_NUMBER
int new_secret_number(void) {
  return rand() % MAX_NUMBER + 1;
}

// Repeatedly reads user guesses and tells the user if the guess is low,
// high, or correct. When correct, prints other information
void read_guesses(int secret_number) {
  int guess, num_guesses = 0;
  for (;;) {
    num_guesses++;
    printf("Enter guess: ");
    scanf("%d", &guess);
    if (guess == secret_number) {
      printf("You won in %d guesses!\n\n", num_guesses);
      return;
    } else if (guess < secret_number) {
      printf("Too low; try again\n");
    } else if (guess > secret_number) {
      printf("Too high; try again\n");
    }
  }
}
