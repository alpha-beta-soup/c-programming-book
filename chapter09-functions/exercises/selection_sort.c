// Selection sort

#include <stdio.h>
#include <stdlib.h>

#define N 10

void selectionsort(int a[], int length);
int index_of_max(int a[], int length);


int main() {
  int a[N], i;

  printf("Enter %d numbers to be sorted: ", N);
  for (i = 0; i < N; i++) {
    scanf("%d", &a[i]);
  }

  selectionsort(a, N);

  printf("In sorted order: ");
  for (i = 0; i < N; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");

  exit(EXIT_SUCCESS);

}

void selectionsort(int a[], int n) {
  if (n > 1) {
    // Move the largest element to the end of the unsorted sublist
    // Replacing it with what is in that place
    int last;
    int max_index = index_of_max(a, n);
    last = a[n-1];
    a[n-1] = a[max_index];
    a[max_index] = last;
    selectionsort(a, --n);
  }
  return;
}


int index_of_max(int a[], int n) {
  int i;
  int max = a[0];
  int max_index = 0;
  for (i = 1; i < n; i++) {
    if (a[i] > max) {
      max = a[i];
      max_index = i;
    }
  }
  return max_index;
}
