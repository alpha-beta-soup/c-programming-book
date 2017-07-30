// Checks numbers for repeated digits

#include <stdio.h>

#define TRUE 1
#define FALSE 0

typedef int Bool;

int main() {
  Bool digit_seen[10] = {0}; //  Initialises all to 0 (FALSE)
  int digit;
  long int m, n;
  printf("Enter numbers (<= 0 to end): ");

  scanf("%ld", &n);

  while (n > 0) {
    m = n;
    printf("%ld: ", m);
    while (m > 0) {
      digit = m % 10;
      if (digit_seen[digit]) {
       break;
      }
      digit_seen[digit] = TRUE;
      m /= 10;
    }

    if (m > 0) {
      printf("Repeated digit (%d)\n\n", digit);
    } else {
      printf("No repeated digits\n\n");
    }
    scanf("%ld", &n);
  }


  return 0;
}
