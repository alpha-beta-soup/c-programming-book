// Repacles a loop with a loop with an empty body

#include <stdio.h>

int main() {
  int m, n;
  // for (n =0; m > 0; n++) {
  //   m /= 2;
  // }
  m = 50;
  for (n = 0; m > 0; n++, m /= 2);
  return 0;
}
