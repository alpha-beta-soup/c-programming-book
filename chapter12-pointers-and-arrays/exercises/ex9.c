// Checks if a message is a palindrome

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define MSG_LEN 20 // Maximum length of message
bool is_palindrome(char *a, int n);

int main(void){
  char msg[MSG_LEN], ch;
  int i = 0;
  printf("Enter a message: ");
  while (i < MSG_LEN && (ch = getchar()) != '\n') {
    if (isalpha(ch)) {
      msg[i++] = tolower(ch);
    }
  }
  if (is_palindrome(msg, i - 1))
    printf("Palindrome\n");
  else
    printf("Not a palindrome\n");
  return 0;
}

bool is_palindrome(char *a, int n) {
  char *left, *right;
  for (left = a, right = a + n; left <= right; left++, right--)
    if (*left != *right)
      return false;
  return true;
}
