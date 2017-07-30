// Checks whether a number is prime, ut does it efficiently by only checking
// divisors up to the square root of the candidate.

#include <stdio.h>

int main() {
  int d, n;
  printf("Enter a positive integer: ");
  scanf("%d", &n);
  for (d = 2; (d * d) <= n; d++) {
    if (n % d == 0) {
      break;
    }
  }
  if ((d * d) <= n) {
    printf("%d is divisible by %d\n", n, d);
  } else {
    printf("%d is prime\n", n);
  }
  return 0;
}
