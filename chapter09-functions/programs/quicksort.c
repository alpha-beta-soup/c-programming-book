// Sorts an array of integers using Quicksort

// Notes
// The partioning algorithm isn't efficient (could take the media of the first,
//    middle and last element, rather than just taking the first)
// A simpler method would be faster the small arrays (length < 25)
// Quicksort is actually faster with a non-recursive implementation

#include <stdio.h>
#include <stdlib.h>

#define N 10

void quicksort(int a[], int low, int high);
int split(int a[], int low, int high);

int main() {
  int a[N], i;

  printf("Enter %d numbers to be sorted: ", N);
  for (i = 0; i < N; i++) {
    scanf("%d", &a[i]);
  }

  quicksort(a, 0, N - 1);

  printf("In sorted order: ");
  for (i = 0; i < N; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");

  exit(EXIT_SUCCESS);
}

void quicksort(int a[], int low, int high) {
  int middle;

  if (low >= high) {
    return;
  }
  middle = split(a, low, high);
  quicksort(a, low, middle - 1);
  quicksort(a, middle + 1, high);
}

int split(int a[], int low, int high) {
  int part_element = a[low];
  for (;;) {
    while (low < high && part_element <= a[high]){
      high--;
    }
    if (low >= high) {
      break;
    }
    a[low++] = a[high];

    while (low < high && a[low] <= part_element) {
      low++;
    }
    if (low >= high) {
      break;
    }
    a[high--] = a[low];
  }

  a[high] = part_element;
  return high;
}
