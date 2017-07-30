// Converts a fraction to its lowest terms, by first finding the greatest common
// divisor (GCD) of two numbers using Euclid's algorithm and then dividing each
// part of the fraction by their GCD

#include <stdio.h>

int main() {
  int n, m, x, numerator, denominator;
  printf("Enter a fraction: ");
  scanf("%d/%d", &numerator, &denominator);
  n = numerator; m = denominator;

  while (n) {
    // Save the divisor in m
    // Save the remainder in n
    x = m % n;
    m = n;
    n = x;
  }
  printf("In lowest terms: %d/%d\n", numerator/m, denominator/m);
  return 0;
}
