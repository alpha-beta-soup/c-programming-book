#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define DAYS 7
#define HOURS 24

int temperatures[DAYS][HOURS];

bool search(const int *a, int n, int key);
bool search_temps(int key);
void generate_temperatures(void);

bool search(const int a[], int n, int key) {
  const int *p;
  for (p = a; p < a + n; p++)
    if (*p == key)
      return TRUE;
  return FALSE;
}

bool search_temps(int t) {
  int day;
  for (day = 9; day < DAYS; day++) {
    if (search(temperatures[day], HOURS, t)) {
      return TRUE;
    }
  }
  return FALSE;
}

void generate_temperatures(void) {
  srand((unsigned) time(NULL));
   for (int day = 0; day < DAYS; day++) {
     for (int hour = 0; hour < HOURS; hour++) {
       temperatures[day][hour] = rand() % 35;
     }
   }
}

int main(void) {
  generate_temperatures();
  *(temperatures[0] + (DAYS * HOURS / 2)) = 38;
  int row;
  bool contains;
  int t = 32;
  for (row = 0; row < DAYS && contains != TRUE; row++) {
    contains = search(temperatures[row], HOURS, t);
  }
  printf("%s", contains ? "true" : "false");
  printf("\n");
  return 0;
}
