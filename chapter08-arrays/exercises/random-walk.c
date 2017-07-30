#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define GRID_SIZE 10
#define TRUE 1
#define FALSE 0
#define OPTIONS 4
#define START 'A'
#define END 'Z'

typedef int Bool;

int main() {
  char grid[GRID_SIZE][GRID_SIZE] = {};
  int x = 0;
  int y = 0;
  int next_x = 0;
  int next_y = 0;
  int move, open_spaces;
  Bool placed = FALSE;
  Bool examined_spaces[4] = {};
  // Initialise a random number generator using current time,
  // to ensure it's different each loop
  srand((unsigned) time(NULL));
  // Loop alphabet
  for (char c = START; c <= END; c++) {
    open_spaces = OPTIONS;
    memset(examined_spaces, 0, sizeof(Bool)*4); // Empty examined spaces array

    grid[x][y] = c;
    // Determine the next position
    if (c == END) {
      // end of iteration
      placed = TRUE;
    } else {
      // Need to determine the position of the next character
      placed = FALSE;
    }
    // Placed, calculating position of next character
    while ((!placed) && (open_spaces > 0)) {
      next_x = x;
      next_y = y;
      move = rand() % OPTIONS;
      if (examined_spaces[move] == TRUE) {
        // Already examined this move
        continue;
      }
      if (examined_spaces[move] == FALSE) {
        // A new move
        open_spaces--;
        examined_spaces[move] = TRUE;
      }
      switch (move) {
        case 0: next_y--; break; // up
        case 1: next_x++; break; // right
        case 2: next_y++; break; // down
        case 3: next_x--; break; // left
      }
      if (next_y + 1 > GRID_SIZE || next_y < 0 || next_x + 1 > GRID_SIZE || next_x < 0) {
        // Out of bounds
        continue;
      } else if (grid[next_x][next_y] != 0) {
        // Already occupied by a character
        continue;
      } else {
        // Successful placement
        placed = TRUE;
        x = next_x;
        y = next_y;
      }
    }
    if (open_spaces <= 0 && !placed) {
      // No more empty spaces
      break;
    }
  }
  for (x = 0; x < GRID_SIZE; x++) {
    for (y = 0; y < GRID_SIZE; y++) {
      if (grid[x][y] == 0) {
        printf(". ");
      } else {
        printf("%c ", grid[x][y]);
      }
    }
    printf("\n");
  }
  exit(EXIT_SUCCESS);
}
