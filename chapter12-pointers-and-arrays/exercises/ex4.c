// Reverses a message entered by a user

#include <stdio.h>

#define MAX 20 // Maximum length of message

int main(){
  char a[MAX];
  char *p;
  char ch;
  p = &a[0];
  printf("Enter a message: ");
  while ((ch = getchar()) != '\n') {
    *p++ = ch;
  }
  printf("Reversal is: ");
  while (p >= &a[0]) {
    putchar(*p--);
  }
  putchar('\n');
  return 0;
}
