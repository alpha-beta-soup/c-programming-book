// l33t speaker

#include <stdio.h>
#include <ctype.h>

#define EXCLAM_COUNT 10
#define MAX_MSG_LEN 100
#define BIFF_FILTER_LEN (int) (sizeof(biff_filter_char) / sizeof(biff_filter_char[0]))


int main() {
  char msg[MAX_MSG_LEN] = {0};
  int len, i;
  // Ask for input
  printf("Enter message: ");
  // Read input into array; convert character into upper case
  for (len = 0; len < MAX_MSG_LEN && ((msg[len] = toupper(getchar())) != '\n'); len++) {
    // Empty loop
  }
  printf("In B1FF-speak: ");
  // Pass characters through biff filter
  // Check if character has BIFF translation
  for (i = 0; i < len; i++) {
    switch (msg[i]) {
      case 'A':   putchar('4');
                  break;
      case 'B':   putchar('8');
                  break;
      case 'E':   putchar('3');
                  break;
      case 'I':   putchar('1');
                  break;
      case 'O':   putchar('0');
                  break;
      case 'S':   putchar('5');
                  break;
      default:    putchar(msg[i]);
                  break;
    }
  }
  // Add exclamation marks
  for (i = 1; i <= EXCLAM_COUNT; i++) {
    printf("!");
  }
  printf("\n");
  return 0;
}
