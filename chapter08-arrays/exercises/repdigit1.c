// Checks numbers for repeated digits

#include <stdio.h>

int main() {
  int digit_seen_count[10] = {0}; // Initialises all to 0
  int digit, i;
  long int n;
  printf("Enter a number: ");
  scanf("%ld", &n);

  while (n > 0) {
    digit = n % 10;
    digit_seen_count[digit]++;
    n /= 10;
  }

  printf("Repeated digit(s): ");

  for (i = 0; i < 10; i++) {
    if (digit_seen_count[i] > 1) {
      printf("%d ", i);
    }
  }
  printf("\n");
  return 0;
}
