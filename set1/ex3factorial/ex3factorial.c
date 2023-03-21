/*
 *  Calculate factorial using while loops
 *
 * Samples:
 * - while_stmt.c
 */
#include <stdio.h>
//#include <stdbool.h>


int main(void) {
    
    int number;
    long long int factorial = 1;
    
    printf("Enter an integer (less than 20) > ");
    scanf("%d", &number);
        
    while (number != 0) {
        
        factorial = factorial * number;
        number--;
    }
    
    printf("Factorial = %lld \n", factorial);
    
    // TODO. Do it once then add while (loop) around

    return 0;
}
