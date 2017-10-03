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
void print_day_temperature(int);

void generate_temperatures(void) {
  srand((unsigned) time(NULL));
  for (int day = 0; day < DAYS; day++) {
    for (int hour = 0; hour < HOURS; hour++) {
      temperatures[day][hour] = rand() % 35;
    }
  }
}

void print_day_temperature(int day) {
  int *hour_ptr;
  for (hour_ptr = temperatures[day]; hour_ptr < temperatures[day] + HOURS; hour_ptr++) {
    printf("%2d\t", *hour_ptr);
  }
  printf("\n");
}

int main(void) {
  generate_temperatures();
  // *(temperatures[0] + (DAYS * HOURS / 2)) = 32;
  int day = 2;
  print_day_temperature(day);
  return 0;
}
