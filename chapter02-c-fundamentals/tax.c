#include <stdio.h>

int main()
{
  float price;
  printf("Enter a dollar amount: $");
  scanf("%f", &price);
  printf("With 5%% tax added: $%.2f\n", price * 1.05);
  return 0;
}
