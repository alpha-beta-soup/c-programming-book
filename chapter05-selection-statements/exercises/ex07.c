// Converts wind speed in knots to Beaufort scale description

#include <stdio.h>

int main(void)
{
    int wind;

    printf("Enter the wind speed in knots: ");
    scanf("%d", &wind);


    if (wind < 1) {
      printf("Calm\n");
    } else if (wind >= 1 && wind <= 3) {
      printf("Light air\n");
    } else if (wind >= 4 && wind <= 27) {
      printf("Breeze\n");
    } else if (wind >= 28 && wind <= 47) {
      printf("Gale\n");
    } else if (wind >= 48 && wind <= 63) {
      printf("Storm\n");
    } else if (wind >= 64) {
      printf("Hurricane\n");
    }
}
