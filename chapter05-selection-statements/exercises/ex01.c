// Calculates a broker's commission

#include <stdio.h>

int main(){
  int i, j, k;
  i = 2; j = 3;
  k = i * j == 6;
  printf("%d", k); // 1

  i = 5; j = 10; k = 1;
  printf("%d", k > i < j); // 1

  i = 3; j = 2; k = 1;
  printf("%d", i < j == j < k); // 1

  i = 3; j = 4; k = 5;
  printf("%d", i % j + i < k); // 0

  i = 10; j = 5;
  printf("%d", !i < j); // 1

  i = 2; j = 1;
  printf("%d", !!i + !j); // 1


  i = 5; j = 0; k = -5;
  printf("%d", i && j || k); // 1

  i = 1; j = 2; k = 3;
  printf("%d", i < j || k); // 1
}
