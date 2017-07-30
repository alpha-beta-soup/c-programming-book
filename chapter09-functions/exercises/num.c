// Finds the number of digits in a number

#include <stdio.h>

int num_digits(int number);

int main() {
  int n;
  printf("Enter an integer: ");
  scanf("%d", &n);
  printf("Number of digits: %d\n", num_digits(n));
  return 0;
}

int num_digits(int n) {
  int digits;
  for (digits = 1; n /= 10; digits++) {
    // Empty
  }
  return digits;
}
