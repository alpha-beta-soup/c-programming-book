// Sums an array,
// using pointer arithmetic rather than array subscripting.

#include <stdio.h>

int sum_array(int a[], int n) {
  int *p, sum;

  sum = 0;
  for (p = a; p < a + n; p++) {
    sum += *p;
  }
  return sum;
}

int main(void)
{
  int numbers[] = {1,2,3,4,5};

  int total = sum_array(&numbers[0], 5);
  printf("Total: %d", total);

  return 0;
}
