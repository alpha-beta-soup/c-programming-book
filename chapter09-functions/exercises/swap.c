// Doesn't actually swap
// (Swapping would require that we pass pointers to two variables so that a
// function can change them directly)

#include <stdio.h>

void swap(int a, int b);

int main() {
  int x = 1, y = 2;

  swap(x, y);
  printf("x = %d, y = %d\n", x, y);
  return 0;
}

void swap(int a, int b) {
  int temp;
  temp = a;
  a = b;
  b = temp;
}
