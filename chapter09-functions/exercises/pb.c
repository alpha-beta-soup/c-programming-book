// Mystery function

#include <stdio.h>

void pb(int number);

int main() {
  int n;
  printf("Enter an integer: ");
  scanf("%d", &n);
  pb(n);
  printf("\n");
  return 0;
}

void pb(int n) {
  if (n != 0) {
    pb(n / 2);
    putchar('0' + n % 2);
  }
}
