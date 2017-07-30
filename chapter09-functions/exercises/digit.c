// Finds the number of digits in a number

#include <stdio.h>

int num_digits(int number);
int digits(int n, int k);

int main() {
  int n, k;
  printf("n k: ");
  scanf("%d %d", &n, &k);
  printf("kth digit of n: %d\n", digits(n, k));
  return 0;
}

int digits(int n, int k) {
  int digit;
  if (k > num_digits(n)) {
    return -1;
  }
  while (k) {
    digit = n % 10;
    n /= 10;
    k--;
  }
  return digit;
}

int num_digits(int n) {
  int digits;
  for (digits = 1; n /= 10; digits++) {
    // Empty
  }
  return digits;
}
