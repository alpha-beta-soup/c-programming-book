// Prints a table of compound interest

#include <stdio.h>

#define NUM_RATES ((int) sizeof(value)/sizeof(value[0]))
#define INITIAL_BALANCE 100.0

int main() {
  int unsigned i, month, num_years, year;
  float low_rate;
  float value[5];

  printf("Enter interest rate: ");
  scanf("%f", &low_rate);
  printf("Enter number of years: ");
  scanf("%d", &num_years);

  printf("\nYears\t");
  for (i = 0; i < NUM_RATES; i++) {
    printf("%4.2f%%\t", low_rate + i);
    value[i] = INITIAL_BALANCE;
  }
  printf("\n");

  for (year = 1; year <= num_years; year++) {
    printf("%3d\t", year);
    for (i = 0; i < NUM_RATES; i++) {
      // Calculate interest monthly
      for (month = 1; month <= 12; month++) {
        value[i] += (double) ((low_rate + i) / 12) / 100.0 * value[i];
      }
      printf("%7.2f\t", value[i]);
    }
    printf("\n");
  }
  return 0;
}
