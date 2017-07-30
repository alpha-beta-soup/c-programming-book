// Computes the pariwise averages of three numbers
#include <stdio.h>

float average(float a, float b) {
  return (a + b) / 2;
}

int main() {
  float x, y, z;

  printf("Enter three numbers: ");
  scanf("%f%f%f", &x, &y, &z);
  printf("Average of %g and %g: %g\n", x, y, average(x, y));
  printf("Average of %g and %g: %g\n", y, z, average(y, z));
  printf("Average of %g and %g: %g\n", x, z, average(x, z));

  return 0;
}
