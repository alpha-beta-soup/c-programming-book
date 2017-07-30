#include <stdio.h>

void find_two_largest(int a[], int n, int *largest, int *second_largest);

int main(void)
{
    int a[10] = {38, 4, 38, 84, 65, 9, 5, 14, 76, 49};
    int largest = 0, second_largest = 0;
    find_two_largest(a, sizeof(a) / sizeof(a[0]), &largest, &second_largest);
    printf("Largest: %d\n", largest);
    printf("Second largest: %d\n", second_largest);
    return 0;
}

void find_two_largest(int a[], int n, int *largest, int *second_largest)
{
  int i;
  for (i = 0; i < n; i++) {
    if (a[i] > *largest) {
      *second_largest = *largest;
      *largest = a[i];
    } else if (a[i] > *second_largest) {
      *second_largest = a[i];
    }
  }
}
