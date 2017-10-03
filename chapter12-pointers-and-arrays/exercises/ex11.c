#include <stdio.h>
#include <stdbool.h>

#define TRUE 1
#define FALSE 0

bool search(int a[], int n, int key) {
  int *p;
  for (p = a; p < a + n; p++)
    if (*p == key)
      return TRUE;
  return FALSE;
}

int main(void) {
  int numbers[] = {1,2,3,4,5};
  bool contains = search(&numbers[0], 5, 6);
  printf("%s", contains ? "true" : "false");
  printf("\n");
  return 0;
}
