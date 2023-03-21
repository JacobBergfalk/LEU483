#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265359

int main() {

    double radius, height;
    double sur_area, volume;

    printf("Enter the radius of the cylinder: \n");
    scanf("%lf", &radius);

    printf("Enter the height of the cylinder: \n");
    scanf("%lf", &height);

    sur_area = 2 *PI* (radius *height + pow(radius, 2));
    volume = PI * pow(radius, 2) * height;

    printf("The cylinders surfice area: %f \n The cylinders volume: %f \n", sur_area, volume);

    return 0;
}