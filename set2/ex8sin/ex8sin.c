#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

//  (-1)^n * x^(2*n + 1) / (2*n + 1)

double sin_f(double x);

double factorial_f(double num);

int main () {
    
    double x = 2.0;
    double egen_funktion = sin_f(x);
    double c_funktion = sin(x);

    printf("Egen funktion: %f \n", egen_funktion);
    printf("c_funktion: %f \n", c_funktion);
    printf("Skillnad till std: %f", c_funktion - egen_funktion);

    return 0;
}


double sin_f(double x) {

    double sum, term;
    long int i = 0;

    while(true) {
        
        term = pow(-1, i) * pow(x, 2*i + 1)/factorial_f(2*i + 1);

        if(fabs(term) < 0.01) {
            break;
        }

        sum += term;
        i++;
    }

    return sum;
}

double factorial_f(double num) {

    double sum = 1;

    for(int i = num; i > 0; i--) {

        sum *= i;
    }

    return sum;
}