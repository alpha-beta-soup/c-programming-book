// Prints integer constants in decimal

#include <stdio.h>

int main() {
  int A = 077, B = 0x77, C = 0XABC;
  printf("%d %d %d\n", A, B, C);
  // 077 (octal) is (7 x 8) + (7 * 1) == 63  (decimal)
  // 0x77 (hexadecimal) is (7 * 16) + (7 * 1) == 119 (decimal)
  // 0XABC (hexadecimal) is (10 * 256) + (11 * 16) + (12 * 1) = 2748 decimal
  return 0;
}
