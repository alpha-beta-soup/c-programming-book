// Translates an alpahbetic phone number into numeric form:
//
// CALLATT → 2255288
//
// 1-800-COL-LECT → 1-800-265-5328

// Permitted to assume all character input that should be transformed is uppercase

#include <stdio.h>

int main() {

  char ch;
  printf("Enter phone number: ");

  while ((ch = getchar()) != '\n') {
    // Transform
    switch(ch) {
      case 'A':
      case 'B':
      case 'C':
        printf("2");
        break;
      case 'D':
      case 'E':
      case 'F':
        printf("3");
        break;
      case 'G':
      case 'H':
      case 'I':
        printf("4");
        break;
      case 'J':
      case 'K':
      case 'L':
        printf("5");
        break;
      case 'M':
      case 'N':
      case 'O':
        printf("6");
        break;
      case 'P':
      case 'Q':
      case 'R':
      case 'S':
        printf("7");
        break;
      case 'T':
      case 'U':
      case 'V':
        printf("8");
        break;
      case 'W':
      case 'X':
      case 'Y':
      case 'Z':
        printf("9");
        break;
      default:
        putchar(ch);
    }
  }
  printf("\n");
  return 0;
}
