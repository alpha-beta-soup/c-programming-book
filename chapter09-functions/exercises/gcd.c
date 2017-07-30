// Finds the greatest common divisor (GCD) of two numbers using Euclid's
// algorithm

#include <stdio.h>

int gcd(int n, int m);

int main() {
  int n, m;
  printf("Enter two integers: ");
  scanf("%d %d", &n, &m);
  printf("Greatest common divisor: %d\n", gcd(n, m));
  return 0;
}

int gcd(int n, int m) {
  // Returns the greatest common divisor of n and m
  int x;
  while (n) { // Until there is no remainder
    x = m % n; // Get remainder
    m = n; // Save the divisor in m
    n = x; // Save the remainder in n
  }
  return m;
}
