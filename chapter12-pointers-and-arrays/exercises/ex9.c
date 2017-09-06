// Checks if a message is a palindrome

#include <stdio.h>
#include <ctype.h>

#define MSG_LEN 20 // Maximum length of message

int main(void){
  char msg[MSG_LEN], ch;
  char *p = msg;
  char *q = p;
  printf("Enter a message: ");
  while (p < msg + MSG_LEN) {
    ch = getchar();
    if (ch == '\n') {
      q--;
      break;
    }
    if (isalpha(ch)) {
      *q++ = tolower(ch);
    }
  }
  while (p <= q) {
    if (!(*p == *q)) {
      printf("Not a palindrome\n");
      return 0;
    }
    p++;
    q--;
  }
  printf("Palindrome\n");
  return 0;
}
