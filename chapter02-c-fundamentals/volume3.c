#include <stdio.h>

#define PI 3.14159265358979323846

int main()
{
    float radius, volume;

    printf("Enter radius of a sphere: ");
    scanf("%f", &radius);

    volume = 4.0/3.0 * PI * (radius * radius * radius);

    printf("Volume of a sphere of radius %.1f: %.1f\n", radius, volume);

    return 0;

}
