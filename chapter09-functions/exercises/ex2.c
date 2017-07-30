// Computes the pariwise averages of three numbers
#include <stdio.h>

#define TRUE 1
#define FALSE 0

typedef int Bool;

Bool check(int x, int y, int z);

int main() {
  check(4, 5, 10);
  return 0;
}


Bool check(int x, int y, int n) {
  return (0 <= x && x <= n - 1) && (0 <= y && y <= n - 1);
}
