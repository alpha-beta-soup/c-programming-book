// Converts 24-hour time to 12-hour time

#include <stdio.h>

int main(void)
{
    int hour, min, meridian;

    printf("Enter a 24 hour time: ");
    scanf("%d:%d", &hour, &min);

    printf("Equivalent 24-hour time: ");
    meridian = hour >= 12 ? 1 : 0;
    hour = hour > 12 ? hour - 12 : hour;
    printf("%.2d:%.2d %s\n", hour, min, meridian ? "PM" : "AM");

    return 0;
}
