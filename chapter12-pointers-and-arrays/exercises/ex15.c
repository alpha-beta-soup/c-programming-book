#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define DAYS 7
#define HOURS 24

int temperatures[DAYS][HOURS];

void generate_temperatures(void);
int find_largest(int);
void print_highest_day_temperature(int);

void generate_temperatures(void) {
  srand((unsigned) time(NULL));
  for (int day = 0; day < DAYS; day++) {
    for (int hour = 0; hour < HOURS; hour++) {
      temperatures[day][hour] = rand() % 36;
    }
  }
}

int find_largest(int day) {
  int max = temperatures[day][0];
  const int *p;
  for (p = &temperatures[day][0]; p < &temperatures[day][HOURS]; p++) {
    if (*p > max) {
      max = *p;
    }
  }
  return max;
}

void print_highest_day_temperature(int day) {
  int max = find_largest(day);
  printf("%2d", max);
}

int main(void) {
  generate_temperatures();
  // *(temperatures[0] + (DAYS * HOURS / 2)) = 32;
  int day = 2;
  for (day = 0; day < DAYS; day++) {
    print_highest_day_temperature(day);
    printf("\n");
  }
  return 0;
}
