// Finds the greatest common divisor (GCD) of two numbers using Euclid's
// algorithm

#include <stdio.h>

int main() {
  int n, m, x;
  printf("Enter two integers: ");
  scanf("%d %d", &n, &m);

  while (n) {
    // Save the divisor in m
    // Save the remainder in n
    x = m % n;
    m = n;
    n = x;
  }
  printf("Greatest common divisor: %d\n", m);
  return 0;
}
