// Calculates the number of digits in an integer,
// by repeatedly dividing input by 10 until the value is 0 (the count of the
// number of divisons is the number of digits)

#include <stdio.h>

int main() {
  int digits = 0;
  int input;

  printf("Enter a non-negative integer: ");
  scanf("%d", &input);

  do {
     digits++;
  } while (input /= 10);

  printf("The number has %d digit(s).\n", digits);

  return 0;

}
