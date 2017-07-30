#include <stdio.h>
#include <math.h>

int main()
{
    float radius, volume;

    printf("Enter radius of a sphere: ");
    scanf("%f", &radius);

    volume = 4.0/3.0 * M_PI * (radius * radius * radius);

    printf("Volume of a sphere of radius %f: %.1f\n", radius, volume);

    return 0;

}
