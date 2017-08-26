// Checks is a message is a pallindrome

#include <stdio.h>
#include <ctype.h>

#define MAX 20 // Maximum length of message

int main(){
  char a[MAX];
  char *p;
  char *q;
  char ch;
  p = &a[0];
  q = p;
  printf("Enter a message: ");
  while ((ch = getchar()) != '\n') {
    if (isalpha(ch)) {
      *q++ = tolower(ch);
    }
  }
  q--;
  while (p < q) {
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
