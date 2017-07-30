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

  printf("Digit:      ");
  for (i = 0; i < 10; i++) {
    printf("%3d", i);
  }
  printf("\nOccurrences:");
  for (i = 0; i < 10; i++) {
    printf("%3d", digit_seen_count[i]);
  }
  printf("\n");
  return 0;
}
