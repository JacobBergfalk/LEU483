/*
 *  Calculate deg <-> rad using id statement
 *
 *   Samples:
 *  - if_stmt.c
 */
#include<stdio.h>

// #define PI 3.1415926    // Define a constant by macro.


int main(void) {

    int selection;
    float input;
    float result;
    const double PI = 3.1415926;

    printf("Select\n 1) For Deg to rad\n 2) For Rad to deg\n> ");
    scanf("%d", &selection);
    printf("Type in Degrees or radians to convert \n");
    scanf("%f", &input);
    
    if(selection == 1) {
        result = input * PI / 180;
        printf("%.2f Degree to radians is: %.2f \n", input, result);
    
    } else {
        result = input * 180 / PI;
        printf("%.2f Radians to degree is: %.2f \n", input, result);
    }
    
    return 0;
}


