// Computes a Universal Product Code check digit

#include <stdio.h>

int main(){
  int i, j, k;
  i = 5; j = 3;
  printf("%d %d\n", i / j, i % j);

  i = 2; j = 3;
  printf("%d\n", (i + 10) % j);

  i = 7; j = 8; k = 9;
  printf("%d\n", (i + 10) % k / j);

  i = 1; j = 2; k = 3;
  printf("%d\n", (i + 5) % (j + 2) / k);

  printf("%d\n", -10/5);
  printf("%d\n\n", -(10/5));

  i = 7; j = 8;
  i *= j + 1;
  printf("%d %d\n", i, j); // 63 8
  // 7 *= 9
  // leaving 63 (side-effect), 8

  i = j = k = 1;
  i += j += k;
  printf("%d %d %d\n", i, j, k); // 3 2 1

  i = 1; j = 2; k = 3;
  i -= j -= k; // right associativity
  printf("%d %d %d\n", i, j, j); // 2 -1 -1

  i = 2; j = 1; k = 0;
  i *= j *= k; // right associativity
  printf("%d %d %d\n", i, j, k); // 0 0 0
}
