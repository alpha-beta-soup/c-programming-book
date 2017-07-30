// Finds the largest number given by a user

#include <stdio.h>

int main() {
  float largest, candidate;

  for (;;) {
    printf("Enter a number: ");
    scanf("%f", &candidate);
    if (candidate <= 0) break;
    if (candidate > largest) {
      largest = candidate;
    }
  }
  printf("The largest number entered was %.3f", largest);
  return 0;
}
