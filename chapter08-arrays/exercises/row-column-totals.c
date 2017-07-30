#include <stdio.h>

#define N 5

int main() {
  int numbers[N][N] = {};
  int row, col, sum;

  for (row = 0; row < N; row++) {
    printf("Enter row %d (%d numbers): ", row + 1, N);
    for (col = 0; col < N; col++) {
      scanf("%d", &numbers[row][col]);
    }
  }
  printf("\nRow totals:");
  for (row = 0; row < N; row++) {
    sum = 0;
    for (col = 0; col < N; col++) {
      sum += numbers[row][col];
    }
    printf("%3d", sum);
  }
  printf("\nCol totals:");
  for (col = 0; col < N; col++) {
    sum = 0;
    for (row = 0; row < N; row++) {
      sum += numbers[row][col];
    }
    printf("%3d", sum);
  }
  printf("\n");
  return 0;
}
