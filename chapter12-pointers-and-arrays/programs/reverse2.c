// Reverses a series of numbers (pointer version)

# include <stdio.h>
# define N 10

int main() {
  int a[N], *p;

  printf("Enter %d numbers: ", N);
  for (p = a; p < a + N; p++) {
    // NB. scanf 2nd arg does not need to be &p because p is already a pointer
    scanf("%d", p);
  }

  printf("In reverse order:");
  for (p = a + N -1; p >= a; p--) {
    printf(" %d", *p);
  }
  printf("\n");

  return 0;
}
