// Translates a Scrable word into its face value
//
// pitfall → 12
//
// Both upper- and lower-case letters supported

#include <stdio.h>
#include <ctype.h>

int main() {
  char ch;
  int sum;
  //Ask for input
  printf("Enter a word: ");
  //Parse input (getchar)
  while ((ch = getchar()) != '\n') {
    //Make upper case
    switch (toupper(ch)) {
      //Convert input to value
      //Add value to sum
      case 'A': case 'E': case 'I': case 'L': case 'N': case 'O': case 'R': case 'S': case 'T': case 'U':
        sum += 1;
        break;
      case 'D': case 'G':
        sum += 2;
        break;
      case 'B': case 'C': case 'M': case 'P':
        sum += 3;
        break;
      case 'F': case 'H': case 'V': case 'W': case 'Y':
        sum += 4;
        break;
      case 'K':
        sum += 5;
        break;
      case 'J': case 'X':
        sum += 8;
        break;
      case 'Q': case 'Z':
        sum += 10;
        break;
    }
  }
  //Print sum
  printf("Scrabble value: %d\n", sum);
  return 0;
}
