#include <stdio.h>

int *find_middle(int a[], int n);

int main(void)
{
    int a[10] = {38, 4, 38, 84, 65, 9, 5, 14, 76, 49};
    int *middle = find_middle(a, sizeof(a) / sizeof(a[0]));
    printf("Middle: %d\n", *middle);
    return 0;
}

int *find_middle(int a[], int n)
{
  return &a[n/2];
}
