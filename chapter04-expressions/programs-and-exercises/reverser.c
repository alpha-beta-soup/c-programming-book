// Computes a Universal Product Code check digit

#include <stdio.h>

int main(){
  int in;
  printf("Enter a two-digit number: ");
  scanf("%d", &in);
  printf("The reversal is: %1d%1d\n", in % 10, in / 10);

  printf("Enter a three-digit number: ");
  scanf("%d", &in);
  printf("The reversal is: %1d%1d%d\n", (in % 100) % 10, (in % 100) / 10, in / 100);

  int a, b, c;
  printf("Enter a three-digit number: ");
  scanf("%1d%1d%1d", &a, &b, &c);
  printf("The reversal is: %1d%1d%d\n", c, b, a);

}
