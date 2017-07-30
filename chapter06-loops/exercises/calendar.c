// Prints a calendar

#include <stdio.h>

int main(){
  int total_days, start_day, i;
  printf("Enter number of days in month: ");
  scanf("%d", &total_days);
  printf("Enter starting day of the week: (1=Sun, 7=Sat): ");
  scanf("%d", &start_day);
  int iterations_needed = total_days + (start_day - 1);
  int day = 1;
  for (i = 1; i <= iterations_needed; i++) {
    if (i < start_day) {
      printf("   ");
    } else {
      printf("%3d", day++);
    }
    if (i % 7 == 0) {
      printf("\n");
    }
  }
  printf("\n");
  return 0;
}
