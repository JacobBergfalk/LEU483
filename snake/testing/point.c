#include <stdlib.h>

struct Point
{
    double x;
    double y;
};

void Point_print(const struct Point* self);

int main()
{
    struct Point aPoint;
    aPoint.x = 1.0;         // to access the "public" variables in a struct c use a struct(name).variable.
    aPoint.y = 2.0;

    Point_print(&aPoint);
}

void Point_print(const struct Point *self) 
{
    printf("(%f, %f \n", (*self).x, (*self).y);
}