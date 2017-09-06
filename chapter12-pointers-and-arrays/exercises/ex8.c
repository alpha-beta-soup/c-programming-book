// Reverses a message entered by a user

#include <stdio.h>

#define MSG_LEN 80 // Maximum length of message

int main(void){
  char msg[MSG_LEN], *p;
  printf("Enter a message: ");
  for (p = msg; p < msg + MSG_LEN; p++) {
    *p = getchar();
    if (*p == '\n') {
      break;
    }
  }
  printf("Reversal is: ");
  while (p >= msg) {
    putchar(*p--);
  }
  putchar('\n');
  return 0;
}
