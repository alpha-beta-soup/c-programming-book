// Determines the length of a message

#include <stdio.h>

int main() {
  int len = 0;

  printf("Enter a message: ");
  while (getchar() != '\n') {
    len++;
  }
  printf("Your message was %d character%c long.\n", len, *((len > 1) ? "s" : ""));
  return 0;
}
