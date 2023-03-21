/*
 *   Solving a quadratic equation
 *   https://en.wikipedia.org/wiki/Quadratic_formula
 *   https://www.mathsisfun.com/quadratic-equation-solver.html
 *
 *
 *   See:
 *   - math.c
 */
#include <stdio.h>
#include <math.h>


int main(void) {

    printf("Program to solve a quadratic equation: ");
    printf("ax^2 + bx + c = 0\n");

    double a;
    double b;
    double c;

    printf("Please input a > ");
    scanf("%lf", &a);
    printf("Please input b > ");
    scanf("%lf", &b);
    printf("Please input c > ");
    scanf("%lf", &c);

    double discriminant = b * b - 4 * a * c;
    double root1, root2;
    double x1, x2;
    
    double roten_ur = sqrt(discriminant);

    if( discriminant > 0){
        printf("There are two distinct real roots ");
        x1 = (-b + roten_ur)/(2*a);
        x2 = (-b - roten_ur)/(2*a);
        
    } else if( discriminant < 0 ){
        printf("There are two complex conjugate roots. Can't solve will give nan\n");
        x1 = (-b + roten_ur)/(2*a);
        x2 = (-b - roten_ur)/(2*a);
        
    } else {
        printf("There are two equal real roots ");
        x1 = -b / (2 * a);
        x2 = -b / (2 * a);

    }

    printf("x1 = %f, x2 = %f\n", x1, x2);
    return 0;
}
