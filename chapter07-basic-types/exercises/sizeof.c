#include <stdio.h>

int main() {
  // Printing the result of the sizeof operator requires care because the return
  // type is implementation-defined: you can get around this by first casting
  // to a known type (there are several ways to do this).
  printf("Size of int: %lu\n", (unsigned long) sizeof(int));
  printf("Size of short: %lu\n", (unsigned long) sizeof(short));
  printf("Size of long: %lu\n", (unsigned long) sizeof(long));
  printf("Size of float: %lu\n", (unsigned long) sizeof(float));
  printf("Size of double: %lu\n", (unsigned long) sizeof(double));
  printf("Size of long double: %lu\n", (unsigned long) sizeof(long double));
  return 0;
}
