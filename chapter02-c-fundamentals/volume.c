#include <stdio.h>
#include <math.h>

int main()
{
    int radius = 10;
    float volume;

    volume = 4.0/3.0 * M_PI * (radius * radius * radius);

    printf("Volume of a sphere of radius %d: %.1f\n", radius, volume);

    return 0;

}
