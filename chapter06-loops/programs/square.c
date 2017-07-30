// Prints a table of squares using a while statement

#include <stdio.h>

int main() {
  int i = 1;
  int n;

  printf("This program prints a table of squares.\n");
  printf("Enter number of entries in table: ");
  scanf("%d", &n);

  while (i <= n) {
    // printf("\t%d\t%d\n", i, i*i);
    printf("%10d%10d\n", i, i * i);
    i++;
  }

  return 0;

}
