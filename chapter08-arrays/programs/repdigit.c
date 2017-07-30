// Checks numbers for repeated digits

#include <stdio.h>

#define TRUE 1
#define FALSE 0

typedef int Bool;

int main() {
  Bool digit_seen[10] = {0}; //  Initialises all to 0 (FALSE)
  int digit;
  long int n;
  printf("Enter a number: ");
  scanf("%ld", &n);

  while (n > 0) {
    digit = n % 10;
    if (digit_seen[digit]) {
     break;
    }
    digit_seen[digit] = TRUE;
    n /= 10;
  }

  if (n > 0) {
    printf("Repeated digit (%d)\n\n", digit);
  } else {
    printf("No repeated digits\n\n");
  }
  return 0;
}
