// Finds the day of year (1-366) implied by a date

#include <stdio.h>

#define TRUE 1
#define FALSE 0

typedef int Bool;

int day_of_year(int year, int month, int day);
int days_in_month(int month, int year);
Bool is_leap_year(int year);

int main() {
  int y, m, d;
  printf("Enter a date (yyyy-mm-dd): ");
  scanf("%d-%d-%d", &y, &m, &d);
  printf("Day of year: %d\n", day_of_year(y, m, d));
  return 0;
}

int day_of_year(int y, int m, int d) {
  int month, day = 0;
  for (month = 1; month < m; month++) {
    day += days_in_month(month, y);
  }
  return day + d;
}

Bool is_leap_year(int year) {
  if (year % 4 == 0) {
    // Most often a leap year...
    if (year % 100 == 0 && year % 400 == 0) {
      return TRUE;
    } else {
      return FALSE;
    }
    return TRUE;
  }
  return FALSE;
}

int days_in_month(int month, int year) {
  int days;
  switch(month) {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
      days = 31;
      break;
    case 4: case 6: case 9: case 11:
      days = 30;
      break;
    case 2:
      days = is_leap_year(year) ? 29 : 28;
      break;
  }
  return days;
}
