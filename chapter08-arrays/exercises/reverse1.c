// Reverses a series of numbers

#include <stdio.h>

#define N 10
#define LEN (int) (sizeof(a) / sizeof(a[0]))

int main() {
  int a[N], i;
  printf("Enter %d numbers: ", N);
  for (i = 0; i < LEN; i++) {
    scanf("%d", &a[i]);
  }
  // #define LEN (int) (sizeof(a) / sizeof(a[0]))
  printf("In reverse order:");
  for (i = LEN - 1; i >= 0; i--) {
    printf(" %d", a[i]);
  }
  printf("\n");
  return 0;
}
