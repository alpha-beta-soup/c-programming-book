// Prints a table of squares using an odd method that requires no multiplication

#include <stdio.h>

int main() {
  int i, n, odd, square;

  printf("This program prints a table of squares.\n");
  printf("Enter number of entries in table: ");
  scanf("%d", &n);

  for (square = 1, i = 1, odd = 3; i <= n; odd += 2) {
    printf("%10d%10d\n", i, square);
    ++i;
    square += odd;
  }

  return 0;

}
