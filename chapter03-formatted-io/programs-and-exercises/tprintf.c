// Prints int and float values in various formats

#include <stdio.h>

int main()
{
  int i;
  float x;

  i = 40;
  x = 839.21;

  printf("|%d|%5d|%-5d|%5.3d|\n", i, i, i, i);
  printf("|%10.3f|%10.3e|%-10g|\n", x, x, x);
  printf("|%6d,%4d|\n", 86, 1040);
  printf("|%12.5f|\n", 30.253);
  printf("|%12.5e|\n", 30.253);
  printf("|%-6.2g|\n", .0000009979);

  printf("|%-8.1e|\n", x);
  printf("|%10.6e|\n", x);
  printf("|%-8.3f|\n", x);
  printf("|%6f|\n", x);

  return 0;
}
