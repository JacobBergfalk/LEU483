/*
 *  Calculate area of a rectangle
 *
 *  Samples:
 *  - c2f.c
 *  - operators.c
 *  - io.c
 *  - variables.c
 */
#include <stdio.h>

int main(void) {

    printf("Program to calculate the area of a rectangle\n");

    float width;
    float height;

    // ----- Input ----------------

    width = 2.1;
    height = 3.5;

    // -------- Process -----------

    float area;

    area = width * height;

    // ----- Output ----------------

    printf("The area of the rectangle is : %d \n", area);
    
    // %.nf     n = antal decinaltecken. %d skriver ut hela talet utan decimaltecken.

    return 0;
}